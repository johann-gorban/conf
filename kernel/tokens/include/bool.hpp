#pragma once

#include "token.hpp"

class BoolToken : public Token {
public:
    explicit BoolToken(const std::string &data);
};