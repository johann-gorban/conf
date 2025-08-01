#include "preprocessor.hpp"
#include <fstream>
#include <stdexcept>

namespace config {

    std::vector<std::string> Preprocessor::process(const std::string& filepath) {
        std::ifstream in(filepath);
        if (!in.is_open()) {
            throw std::runtime_error("Cannot open file: " + filepath);
        }

        std::vector<std::string> lines;
        std::string line;
        while (std::getline(in, line)) {
            lines.push_back(line);
        }

        return lines;
    }

}
