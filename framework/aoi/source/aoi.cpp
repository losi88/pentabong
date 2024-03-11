#include "aoi/aoi.h"

#include <Windows.h>

#include <fstream>
#include <sstream>

#include <google/protobuf/util/json_util.h>
#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>

#include "config_generated/ari.pb.h"

std::unique_ptr<aoi::AOI, aoi::AOI::Deleter> aoi::AOI::_instance;
std::once_flag aoi::AOI::_flag;

namespace aoi {
AOI* AOI::GetInstance() {
    std::call_once(_flag, [] { _instance.reset(new AOI); });

    return _instance.get();
}

bool AOI::Initialize() {
    char exePath[MAX_PATH] = {0};
    GetModuleFileName(NULL, exePath, MAX_PATH);
    std::cout << exePath << std::endl;

    std::string::size_type pos = std::string(exePath).find_last_of("\\");

    std::string path;
    if (pos == std::string::npos) {
        return "";
    } else {
        path = std::string(exePath).substr(0, pos);
    }
    std::ifstream in(path + "/ari-config.json");
    std::stringstream ss;

    if (false == in.is_open()) {
        return false;
    }

    ss << in.rdbuf();
    in.close();

    ari::AriConfig config;

    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;

    google::protobuf::util::JsonParseOptions options2;
    JsonStringToMessage(ss.str(), &config, options2);

    _ariConfig.reset(new ari::AriConfig(config));
    return true;
}

const ari::AriConfig* const AOI::GetAriConfig() const {
    return _ariConfig.get();
}
}