#pragma once

#include "value/config_value.hpp"

#include <unordered_map>
#include <string>

namespace Config {

class Config {
private:
    std::unordered_map<std::string, ConfigValue> params_;
public:
    ConfigManager(file, const ConfigProcessor *processor = nullptr);

    const ConfigValue get(const std::string &param_name) const;
}

}