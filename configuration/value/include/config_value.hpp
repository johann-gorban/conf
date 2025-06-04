#pragma once

#include <string>

#include "processing/utils/token.hpp"

class ConfigValue {
private:    
    const std::string data_;
public:
    explicit ConfigValue(const token_ptr token);

    const int to_int() const;
    
    bool to_bool() const;
    
    float to_float() const;

    const std::string to_string() const;
};