#pragma once

#include <string>
#include <memory>

namespace config {

typedef enum {
    Key,
    Property,
    Operation
} TokenType;

class Token {
private:
    const std::string data;
    const TokenType type;
public:
    Token(TokenType type, const std::string &data = "");

    TokenType get_type() const;

    // May be inline?
    const std::string to_string() const;
};

using token_ptr = std::shared_ptr<Token>;

}