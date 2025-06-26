#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>
#include <unordered_map>

namespace Config {
    
    struct SoFile {
        std::string name;
        std::string storedPath;
        std::string originalPath;
    };
    
    enum class InjectionMethod {
        STANDARD = 0,
        RIRU = 1,
        CUSTOM_LINKER = 2
    };
    
    struct AppConfig {
        bool enabled = false;
        InjectionMethod injectionMethod = InjectionMethod::STANDARD;
        std::vector<SoFile> soFiles;
    };
    
    struct ModuleConfig {
        bool enabled = true;
        bool hideInjection = false;
        std::unordered_map<std::string, AppConfig> perAppConfig;
    };
    
    // Read configuration from file
    ModuleConfig readConfig();
    
    // Check if app is enabled for injection
    bool isAppEnabled(const std::string& packageName);
    
    // Get SO files for specific app
    std::vector<SoFile> getAppSoFiles(const std::string& packageName);
    
    // Get hide injection setting
    bool shouldHideInjection();
    
    // Get injection method for specific app
    InjectionMethod getAppInjectionMethod(const std::string& packageName);
}

#endif // CONFIG_H