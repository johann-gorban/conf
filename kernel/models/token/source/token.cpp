#include "token.hpp"

Token::Token(TokenType type, const std::string &data) 
    : type(type), data(data) {}

const std::string Token::to_string() const {
    return this->data;
}

TokenType Token::get_type() const {
    return this->type;
}

IntegerToken::IntegerToken(const std::string &data) 
    : Token("integer", data) {}

FloatToken::FloatToken(const std::string &data) 
    : Token("float", data) {}

BoolToken::BoolToken(const std::string &data) 
    : Token("bool", data) {}

StringToken::StringToken(const std::string &data) 
    : Token("string", data) {}