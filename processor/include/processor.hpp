#pragma once

#include "property.hpp"
#include "lexer.hpp"
#include "parser.hpp"

#include <unordered_map>
#include <fstream>
#include <vector>

namespace config {

namespace processing {

class Processor {
private:
    const tokenization::Lexer *lexer;
    const parsing::Parser *parser;
public:
    Processor(const tokenization::Lexer *l = nullptr, const parsing::Parser *p = nullptr);
public:
    config::property_map process(std::ifstream &config_file) const;
private:
    config::property_map organize(const std::vector<token_ptr> &tokens) const;
};

}

}
