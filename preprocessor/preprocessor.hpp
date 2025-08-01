#pragma once

#include <string>
#include <vector>

namespace config {

    class Preprocessor {
    public:
        static std::vector<std::string> process(const std::string& filepath);
    }

}
