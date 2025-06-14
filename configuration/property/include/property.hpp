#pragma once

#include <string>

#include "processing/utils/token.hpp"

class token_ptr;

namespace config {

class Value {
private:    
    const std::string data_;
public:
    explicit Value(const token_ptr token);
public:
    int to_int() const;
    
    bool to_bool() const;
    
    float to_float() const;

    std::string to_string() const;
};

class IntegerValue : public Value {
public:
    explicit IntegerValue(const token_ptr token);
public:
    int to_int() const;
};

class FloatValue : public Value {
public:
    explicit FloatValue(const token_ptr token);
public:
    float to_float() const;
};

class BoolValue : public Value {
public:
    explicit BoolValue(const token_ptr token);
public:
    bool to_bool() const;
};

class StringValue : public Value {
public:
    explicit StringValue(const token_ptr token);
public:
    std::string to_string() const;
};

};