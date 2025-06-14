#pragma once

#include "processor.hpp"

#include <stdexcept>

config::processing::Processor::Processor(const tokenization::lexer *l, const parsing::parser *p) {
    if (!p) {
        // set default parser
        p = new config::processing::parsing:::Parser;
    }

    if (!l) {
        // set default tokenizer (lexer)
        l = new config::processing::tokenization::Lexer;
    }
    
    this->parser = p;
    this->lexer = l;
}

config::property_map config::processing::Processor::process(const std::ifstream &config_file) const {
    // Read the whole file and parse it char by char by lexer
    // Then parse it by parsers
    // Finally organize it to property map
    std::vector<config::token_ptr> tokens;
    
    std::string line;
    while (config_file >> line) {
        auto line_tokens = this->lexer->tokenize(line);
        tokens.insert(tokens.end(), line_tokens.begin(), line_tokens.end());
    }

    tokens = this->parser->parse(tokens);

    return this->organize(tokens);
}

config::property_map config::processing::Processor::organize(const std::vector<config::token_ptr> &tokens) const {
    config::property_map params;

    if (tokens.size() % 3) {
        throw std::runtime_error("Something went wront while organizing the config data");
    }

    for (std::size_t i = 0; i < tokens.size(); i += 2) {
        params[tokens[i]->to_string()] = new config::Property(tokens[i + 2]);
        // Add checking
    }

    return params;
}