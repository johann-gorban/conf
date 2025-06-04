#pragma once

#include <unordered_map>
#include <string>

#include "value/config_value.hpp"

class ConfigManager {
private:
    std::unordered_map<std::string, ConfigValue> params_;
public:
    ConfigManager(file, const ConfigProcessor *processor = nullptr);

    const ConfigValue getenv(const std::string &param_name) const;
}