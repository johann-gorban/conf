#pragma once

#include <string>
#include <memory>

typedef enum {
    Key,
    Value,
    Operation
} TokenType;

class Token {
private:
    const std::string data_;
    const TokenType type_;
public:
    Token(TokenType type, const std::string &data = "");
    // May be inline?
    const std::string to_string() const;
};

using token_ptr = std::shared_ptr<Token>;