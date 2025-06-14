#pragma once

#include "token.hpp"

config::Token::Token(config::TokenType type, const std::string &data) {
    this->type = type; 
    this->data = data;
}

const std::string config::Token::to_string() const {
    return this->data;
}

config::TokenType config::Token::get_type() const {
    return this->type;
}