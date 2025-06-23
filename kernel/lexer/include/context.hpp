#pragma once

#include "states.hpp"
#include "token.hpp"
#include <models/context.hpp>

#include <vector>

namespace config {

    namespace processing {

        namespace tokenization {

            class Context : public config::context::Context {
            private:
                state_ptr state;
                std::string buffer;
            public:
                explicit Context(const state_ptr &start_state);

                std::string get_buffer() const noexcept;

                void clear_buffer() noexcept;
                
                void append_buffer(char c) noexcept;

                void set_state(state_ptr &&state);

                const state_ptr &get_state() const noexcept;
            };
        }
    }
}