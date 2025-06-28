#pragma once

#include <string>
#include <memory>

class Token {
private:
    const std::string data;
    const std::string type;
public:
    Token(const std::string &type, const std::string &data);

    virtual ~Token() = default;
public:
    // inline?
    const std::string get_data() const;

    const std::string get_type() const;
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