#pragma once

#include <string>

#include "processing/utils/token.hpp"

namespace Config {

class Value {
private:    
    const std::string data_;
public:
    explicit ConfigValue(const token_ptr token);

    int to_int() const;
    
    bool to_bool() const;
    
    float to_float() const;

    std::string to_string() const;
};

}