#include "token.hpp"

config::Token::Token(config::TokenType type, const std::string &data) 
    : type(type), data(data) {}

const std::string config::Token::to_string() const {
    return this->data;
}

config::TokenType config::Token::get_type() const {
    return this->type;
}

config::IntegerToken::IntegerToken(const std::string &data) 
    : Token(config::TokenType::Parameter, data) {}

config::FloatToken::FloatToken(const std::string &data) 
    : Token(config::TokenType::Parameter, data) {}

config::BoolToken::BoolToken(const std::string &data) 
    : Token(config::TokenType::Parameter, data) {}

config::StringToken::StringToken(const std::string &data) 
    : Token(config::TokenType::Parameter, data) {}