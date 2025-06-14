#pragma once

#include "property.hpp"

#include <unordered_map>
#include <fstream>
#include <vector>

namespace config {

namespace processing {

class Processor {
private:
    const tokenization::lexer *lexer;
    const parsing::parser *parser;
public:
    Processor(const tokenization::lexer *l = nullptr, const parsing::parser *p = nullptr);
public:
    config::property_map process(const std::ifstream &config_file) const;
private:
    config::property_map organize(const std::vector<token_ptr> &tokens) const;
};

}

}
