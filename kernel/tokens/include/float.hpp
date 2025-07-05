#pragma once

#include "token.hpp"

class FloatToken : public Token {
public:
    explicit FloatToken(const std::string &data);
};