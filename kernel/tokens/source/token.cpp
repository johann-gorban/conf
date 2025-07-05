#include "token.hpp"

Token::Token(const std::string &type, const std::string &data) 
    : type(type), data(data) {}

const std::string Token::get_data() const {
    return this->data;
}

const std::string Token::get_type() const {
    return this->type;
}
