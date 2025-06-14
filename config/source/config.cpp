#include "config.hpp"

#include <stdexcept>

config::Config::Config(const config::processing::Processor *processor) {
    if (!processor) {
        // Set to default processor
        processor = new config::processing::Processor;
    }

    this->processor = processor;
}

void config::Config::init(std::ifstream &config_file) {
    if (config_file.good()) {
        this->processor->process(config_file);
    }
    else {
        throw std::runtime_error("Cannot open the config file by stream");
    }
}

void config::Config::init(const std::string &config_name) {
    std::ifstream config_file(config_name);
    if (config_file.good()) {
        this->processor->process(config_file);
    }
    else {
        throw std::runtime_error("Cannot open the config file by name");
    }
}

config::property_ptr config::Config::get(const std::string &param_name) const {
    if (this->params.count(param_name) == 0) {
        throw std::runtime_error("There is no parameter with such name");
    }
    
    return this->params.at(param_name);
}