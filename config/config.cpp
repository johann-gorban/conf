#include "config.hpp"
#include "preprocessor.hpp"
// #include "parser.hpp"
// #include "analyzer.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace config {

    ConfigProcessor::ConfigProcessor(const std::string& filepath) : config_path(filepath) {}

    void ConfigProcessor::process() {
        auto lines = Preprocessor::process(config_path);
        // auto ast = Praser::process(lines);
        // properties = Lexer::process(ast);
        properties = {}; // Here is stub
    }

    void ConfigProcessor::clear() {
        properties.clear();
    }

    property_ptr ConfigProcessor::get(const std::string& name) const {
        auto it = properties.find(name);
        if (it == properties.end()) {
            throw std::runtime_error("No such property: " + name);
        }
        return it->second;
    }

}
