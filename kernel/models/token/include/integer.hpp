#pragma once

#include "token.hpp"

class IntegerToken : public Token {
public:
    explicit IntegerToken(const std::string &data);
};