#pragma once

#include "states.hpp"
#include "token.hpp"

#include <vector>

namespace config {
    namespace processing {
        namespace tokenization {

            class Context {
            private:
                std::vector<token_ptr> tokens;
                state_ptr state;
                std::string buffer;
            public:
                explicit Context(const state_ptr &start_state);

                std::vector<token_ptr> get_tokens() const noexcept;

                std::string get_buffer() const noexcept;

                void clear_buffer() noexcept;
                
                void append_buffer(char c);

                void append_token(token_ptr &&token);

                void set_state(state_ptr &&state);

                const state_ptr &get_state() const noexcept;
            };
        }
    }
}