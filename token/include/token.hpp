#pragma once

#include <string>
#include <memory>

namespace config {

typedef enum {
    Key,
    Parameter,
    Operation
} TokenType;

class Token {
private:
    const std::string data;
    const TokenType type;
public:
    Token(TokenType type, const std::string &data = "");

    virtual ~Token() = default;
public:
    TokenType get_type() const;

    // May be inline?
    const std::string to_string() const;
};

class IntegerToken : public Token {
public:
    IntegerToken(const int data = 0);
};

class FloatToken : public Token {
public:
    FloatToken(const float data = 0);
};

class BoolToken : public Token {
public:
    BoolToken(const bool data = false);
};

class StringToken : public Token {
public:
    StringToken(const std::string &data = "");
};

}

namespace config {

    using token_ptr = std::shared_ptr<Token>;

}