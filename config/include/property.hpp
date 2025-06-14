#pragma once

#include "token.hpp"

#include <string>
#include <unordered_map>
#include <memory>

namespace config {

class Property {
private:    
    const std::string data_;
public:
    explicit Property(const token_ptr token);

    virtual ~Property() = default;
public:
    virtual int to_int() const = 0;
    
    virtual bool to_bool() const = 0;
    
    virtual float to_float() const = 0;

    virtual std::string to_string() const = 0;
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

using property_ptr = std::shared_ptr<Property>;

using property_map = std::unordered_map<std::string, property_ptr>;

}