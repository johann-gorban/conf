#pragma once

#include "property.hpp"
#include "processor.hpp"

#include <unordered_map>
#include <fstream>
#include <string>

namespace config {

class Config {
private:
    config::property_map params;
    const config::processing::Processor *processor;
public:
    Config(const config::processing::Processor *processor = nullptr);
public:
    void init(const std::ifstream &config_file);

    void init(const std::string &config_name);

    config::Property get(const std::string &param_name) const;
};

};