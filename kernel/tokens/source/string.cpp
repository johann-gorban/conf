#include "string.hpp"

StringToken::StringToken(const std::string &data) 
    : Token("string", data) {}