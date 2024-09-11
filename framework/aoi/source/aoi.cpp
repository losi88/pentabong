#include "aoi/aoi.h"

#include <Windows.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/message.h>
#include <google/protobuf/stubs/status.h>
#include <google/protobuf/text_format.h>
#include <google/protobuf/util/json_util.h>

#include <cstdio>
#include <fstream>

#include "config_generated/ari.pb.h"
#include "datatable_generated/ari-data.pb.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

std::unique_ptr<aoi::AOI, aoi::AOI::Deleter> aoi::AOI::_instance;
std::once_flag aoi::AOI::_flag;
std::unordered_map<std::string, aoi::MessageFactory::Creator>
    aoi::MessageFactory::_messageMap;

namespace aoi {
void MessageFactory::RegisterMessage(const std::string& typeName,
                                     Creator creator) {
    _messageMap[typeName] = creator;
}

std::unique_ptr<google::protobuf::Message> MessageFactory::CreateMessage(
    const std::string& typeName) {
    auto iter = _messageMap.find(typeName);
    if (iter == _messageMap.end()) {
        return nullptr;
    }

    return iter->second();
}

AOI* AOI::GetInstance() {
    std::call_once(_flag, [] { _instance.reset(new AOI); });

    return _instance.get();
}

bool AOI::Initialize() {
    MessageFactory::RegisterMessage(
        "AriConfig", static_cast<MessageFactory::Creator>(
                         []() -> std::unique_ptr<google::protobuf::Message> {
                             return std::make_unique<ari::AriConfig>();
                         }));

    loadConfig();
    return true;
}

std::filesystem::path AOI::getRootPath(const std::string& additionalPath) {
    char exePath[MAX_PATH] = {0};
    GetModuleFileName(NULL, exePath, MAX_PATH);

    std::string::size_type pos = std::string(exePath).find_last_of("\\");
    if (pos == std::string::npos) {
        return std::filesystem::path();
    }

    std::string rootPath = std::string(exePath).substr(0, pos);
    std::string configDirectoryPath = rootPath;
    configDirectoryPath.append(additionalPath);

    return std::filesystem::path(configDirectoryPath);
}

bool AOI::loadConfig() {
    for (const auto& entry :
         std::filesystem::directory_iterator(getRootPath("/../data/config/"))) {
        if (!loadJson(entry)) {
            continue;
        }
    }

    return true;
}

bool AOI::loadDatatable() {
    for (const auto& entry : std::filesystem::directory_iterator(
             getRootPath("/../data/datatable/"))) {
        if (!loadJson(entry)) {
            continue;
        }
    }

    return true;
}

bool AOI::loadJson(const std::filesystem::directory_entry& dirEntry) {
    if (!dirEntry.is_regular_file()) {
        return false;
    }

    if (dirEntry.path().extension() != ".json") {
        return false;
    }
    std::ifstream ifs(dirEntry.path());
    if (!ifs.is_open()) {
        return false;
    }

    std::string jsonString((std::istreambuf_iterator<char>(ifs)),
                           std::istreambuf_iterator<char>());
    ifs.close();

    rapidjson::Document doc;
    if (doc.Parse(jsonString.c_str()).HasParseError()) {
        return false;
    }

    const rapidjson::Value& name = doc["name"];

    std::cout << name.GetString() << std::endl;

    const rapidjson::Value& rows = doc["rows"][name.GetString()];
    rapidjson::StringBuffer buffer;

    buffer.Clear();

    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    rows.Accept(writer);
    std::cout << buffer.GetString() << std::endl;

    auto config = MessageFactory::CreateMessage(name.GetString());
    if (!jsonToMessage(buffer.GetString(), *config.get())) {
        return false;
    }

    std::type_index key = std::type_index(typeid(*config));
    auto ret = _messageMap.emplace(key, std::move(config));
    if (!ret.second) {
        return false;
    }

    return true;
}

bool AOI::jsonToMessage(const std::string& jsonString,
                        google::protobuf::Message& message) {
    google::protobuf::util::JsonParseOptions options;
    options.ignore_unknown_fields = true;

    auto status = google::protobuf::util::JsonStringToMessage(
        jsonString, &message, options);
    if (!status.ok()) {
        std::cerr << "Failed to parse JSON: " << status.ToString() << std::endl;
        return false;
    }
    return true;
}
}  // namespace aoi