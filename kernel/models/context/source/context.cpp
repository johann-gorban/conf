#include "context.hpp"

namespace config {

    namespace context {

        const std::vector<token_ptr> &Context::get_tokens() const noexcept {
            return this->tokens;
        }

        void Context::append_token(token_ptr &&token) {
            this->tokens.push_back(std::move(token));
        }
    }
}