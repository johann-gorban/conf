#pragma once

#include "token.hpp"

#include <vector>
#include <string>

namespace config {

    namespace processing {

        namespace parsing {

            class Parser {
            public:
                virtual std::vector<token_ptr> parse(const std::vector<token_ptr> &tokens) const;
            };

        }

    }

}