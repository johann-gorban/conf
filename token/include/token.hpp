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
    IntegerToken(TokenType type, const std::string &data = "");
};

class FloatToken : public Token {
public:
    FloatToken(TokenType type, const std::string &data = "");
};

class BoolToken : public Token {
public:
    BoolToken(TokenType type, const std::string &data = "");
};

class StringToken : public Token {
public:
    StringToken(TokenType type, const std::string &data = "");
};

}

namespace config {

    using token_ptr = std::shared_ptr<Token>;

}