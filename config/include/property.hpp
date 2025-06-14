#pragma once

#include "token.hpp"

#include <string>
#include <unordered_map>

namespace config {

class Property {
private:    
    const std::string data_;
public:
    explicit Property(const token_ptr token);
public:
    int to_int() const;
    
    bool to_bool() const;
    
    float to_float() const;

    std::string to_string() const;
};

class IntegerValue : public Property {
public:
    explicit IntegerValue(const token_ptr token);
public:
    int to_int() const;
};

class FloatValue : public Property {
public:
    explicit FloatValue(const token_ptr token);
public:
    float to_float() const;
};

class BoolValue : public Property {
public:
    explicit BoolValue(const token_ptr token);
public:
    bool to_bool() const;
};

class StringValue : public Property {
public:
    explicit StringValue(const token_ptr token);
public:
    std::string to_string() const;
};

};

namespace config {

using property_map = std::unordered_map<std::string, config::Property>;

}