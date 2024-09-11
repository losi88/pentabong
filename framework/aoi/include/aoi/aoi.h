#pragma once
#include <filesystem>  // Add this line
#include <functional>
#include <memory>
#include <mutex>
#include <typeindex>
#include <unordered_map>

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"


namespace google {
namespace protobuf {
class Message;
}
}  // namespace google

namespace ari {
class AriConfig;
class AriData;
}  // namespace ari

namespace aoi {
class MessageFactory {
public:
    using Creator = std::function<std::unique_ptr<google::protobuf::Message>()>;
    // using MessageMap = std::unordered_map<std::string, Creator>;
    // using MessagePtr = std::unique_ptr<google::protobuf::Message*>;

    static void RegisterMessage(const std::string& typeName, Creator creator);
    static std::unique_ptr<google::protobuf::Message> CreateMessage(
        const std::string& typeName);

private:
    static std::unordered_map<std::string, Creator> _messageMap;
};

class AOI {
public:
private:
    class Deleter {
    public:
        void operator()(AOI* instance) {
            delete instance;
        }
    };

    static std::unique_ptr<AOI, Deleter> _instance;
    static std::once_flag _flag;
    friend Deleter;

    std::unordered_map<std::type_index,
                       const std::unique_ptr<google::protobuf::Message>>
        _messageMap;

public:
    AOI() = default;
    AOI(const AOI& other) = delete;
    AOI& operator=(const AOI& rhs) = delete;

    AOI(AOI&& other) = default;
    AOI& operator=(AOI&& rhs) = default;
    virtual ~AOI() = default;

    static AOI* GetInstance();

    bool Initialize();
    const ari::AriConfig& GetAriConfig() const;

private:
    std::filesystem::path getRootPath(const std::string& additionalPath);
    bool loadConfig();
    bool loadDatatable();

    bool loadJson(const std::filesystem::directory_entry& dirEntry);

    bool jsonToMessage(const std::string& jsonString,
                       google::protobuf::Message& message);
};
}  // namespace aoi
