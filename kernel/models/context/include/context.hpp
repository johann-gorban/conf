#pragma once

#include "token.hpp"

#include <vector>

namespace config {

    namespace context {

        class Context {
        private:
            std::vector<token_ptr> tokens;
        public:
            virtual ~Context() = default;
        public:
            const std::vector<token_ptr> &get_tokens() const noexcept;

            void append_token(token_ptr &&token);
        };

    }

}