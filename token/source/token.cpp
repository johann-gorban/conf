#pragma once

#include "token.hpp"

config::Token::Token(config::TokenType type, const std::string &data) 
    : type(type), data(data) {}

const std::string config::Token::to_string() const {
    return this->data;
}

config::TokenType config::Token::get_type() const {
    return this->type;
}

config::IntegerToken::IntegerToken(const int data) 
    : Token(config::TokenType::Parameter, std::to_string(data)) {}

config::FloatToken::FloatToken(config::TokenType type, const std::string &data) 
    : Token(config::TokenType::Parameter, std::to_string(data)) {}

config::BoolToken::BoolToken(config::TokenType type, const std::string &data) 
    : Token(config::TokenType::Parameter, std::to_string(data)) {}

config::StringToken::StringToken(config::TokenType type, const std::string &data) 
    : Token(config::TokenType::Parameter, std::to_string(data)) {}