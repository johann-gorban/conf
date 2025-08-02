#include "preprocessor.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

namespace config {

std::vector<std::string> Preprocessor::process(const std::string& filepath) {
    auto lines = read_lines(filepath);

    std::vector<std::string> cleaned_lines;
    for (const auto& line : lines) {
        std::string no_comment = remove_comment(line);
        std::string no_space = remove_space(no_comment);
        if (!no_space.empty()) {
            cleaned_lines.push_back(trimmed);
        }
    }

    return join_block(cleaned_lines);
}

std::vector<std::string> Preprocessor::read_lines(const std::string& filepath) {
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

std::string Preprocessor::remove_comment(const std::string& line) {
    size_t comment_pos = line.find('#');
    return (comment_pos != std::string::npos) ? line.substr(0, comment_pos) : line;
}

std::string Preprocessor::remove_space(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    return (first == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

std::vector<std::string> Preprocessor::join_block(const std::vector<std::string>& lines) {
    std::vector<std::string> result;
    std::string current;

    for (const auto& line : lines) {
        current += line + " ";
        if (!line.empty() && line.back() == ';') {
            result.push_back(trim(current));
            current.clear();
        }
    }

    if (!current.empty()) {
        result.push_back(trim(current));
    }

    return result;
}

}
