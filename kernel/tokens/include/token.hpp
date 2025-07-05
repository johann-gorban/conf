#pragma once

#include <string>

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