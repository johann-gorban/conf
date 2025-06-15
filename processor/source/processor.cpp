#include "processor.hpp"
#include "property_factory.hpp"

#include <stdexcept>

namespace config {

processing::Processor::Processor(const tokenization::Lexer *l, const parsing::Parser *p) {
    if (!p) {
        // set default parser
        p = new processing::parsing::Parser;
    }

    if (!l) {
        // set default tokenizer (lexer)
        l = new processing::tokenization::Lexer;
    }
    
    this->parser = p;
    this->lexer = l;
}

property_map processing::Processor::process(std::ifstream &config_file) const {
    // Read the whole file and parse it char by char by lexer
    // Then parse it by parsers
    // Finally organize it to property map
    std::vector<token_ptr> tokens;
    
    std::string line;
    while (config_file >> line) {
        auto line_tokens = this->lexer->tokenize(line);
        tokens.insert(tokens.end(), line_tokens.begin(), line_tokens.end());
    }

    tokens = this->parser->parse(tokens);

    return this->organize(tokens);
}

property_map processing::Processor::organize(const std::vector<token_ptr> &tokens) const {
    property_map params;

    if (tokens.size() % 3) {
        throw std::runtime_error("Something went wront while organizing the config data");
    }

    PropertyFactory factory;

    for (std::size_t i = 0; i < tokens.size(); i += 2) {
        token_ptr property_token = tokens[i + 2];
        token_ptr op_token = tokens[i + 1];
        token_ptr key_token = tokens[i];

        if (op_token->get_type() != TokenType::Operation ||
            property_token->get_type() != TokenType::Parameter ||
            key_token->get_type() != TokenType::Key    
        ) {
            throw std::runtime_error("Syntax error while organizing catched");
        }

        params[tokens[i]->to_string()] = factory.create(property_token);
    }

    return params;
}

}