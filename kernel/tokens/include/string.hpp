#pragma once

#include "token.hpp"

class StringToken : public Token {
public:
    explicit StringToken(const std::string &data);
};