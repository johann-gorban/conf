#pragma once

#include "token.hpp"

#include <vector>
#include <string>

namespace config {

    namespace processing {

        namespace tokenization {

            class Lexer {
            public:
                virtual std::vector<token_ptr> tokenize(const std::string &s) const;
            };

        }

    }

}