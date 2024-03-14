#pragma once
#include <memory>
#include <mutex>

namespace ari {
class AriConfig;
class AriData;
}

namespace aoi {
class AOI {
public:
private:
    class Deleter {
    public:
        void operator()(AOI* instance) { delete instance; }
    };

    static std::unique_ptr<AOI, Deleter> _instance;
    static std::once_flag _flag;
    friend Deleter;

    std::unique_ptr<ari::AriConfig> _ariConfig;
    std::unique_ptr<ari::AriData> _ariData;

public:
    static AOI* GetInstance();

    bool Initialize();
    const ari::AriConfig& GetAriConfig() const;

private:
    bool loadAriConfig(const std::string& rootPath);
    bool loadAriData(const std::string& rootPath);
};
}
