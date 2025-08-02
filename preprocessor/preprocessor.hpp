#pragma once

#include <string>
#include <vector>

namespace config {

class Preprocessor {
public:
    static std::vector<std::string> process(const std::string& filepath);

private:
    static std::vector<std::string> read_lines(const std::string& filepath);

    static std::string remove_comment(const std::string& line);

    static std::string remove_space(const std::string& str);

    static std::vector<std::string> join_block(const std::vector<std::string>& lines);
};

}
