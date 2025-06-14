#pragma once

#include "property.hpp"

#include <unordered_map>
#include <fstream>
#include <string>

namespace config {

class Config {
private:
    std::unordered_map<std::string, ConfigValue> params;
    Config::Processor *processor;
public:
    Config(const Config::Processor *processor = nullptr);
public:
    void init(const std::ifstream &config_file);

    void init(const std::string &config_name);

    Config::Value get(const std::string &param_name) const;
};

};