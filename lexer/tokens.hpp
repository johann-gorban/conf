#pragma once

#include <string>

namespace config {

    enum TokenType {
        Integer,
        Float,
        String
    }

    class Token {
        std::string data;
    }

}
