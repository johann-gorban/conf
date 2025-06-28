#pragma once

#include <string>
#include <memory>

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
    explicit Token(TokenType type, const std::string &data);

    virtual ~Token() = default;

    TokenType get_type() const;

    // inline?
    const std::string to_string() const;
};

class IntegerToken : public Token {
public:
    explicit IntegerToken(const std::string &data);
};

class FloatToken : public Token {
public:
    explicit FloatToken(const std::string &data);
};

class BoolToken : public Token {
public:
    explicit BoolToken(const std::string &data);
};

class StringToken : public Token {
public:
    explicit StringToken(const std::string &data);
};

using token_ptr = std::shared_ptr<Token>;