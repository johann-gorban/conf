#include "context.hpp"

#include <stdexcept>

namespace config {

    namespace processing {

        namespace tokenization {
            Context::Context(const state_ptr &start_state) : state(start_state), buffer("") {};

            std::string Context::get_buffer() const noexcept {
                return this->buffer;
            }

            void Context::clear_buffer() noexcept {
                this->buffer.clear();
            }

            void Context::append_buffer(char c) noexcept {
                this->buffer += c;
            }

            void Context::set_state(state_ptr &&state) {
                if (!state) {
                    throw std::invalid_argument("State cannot be null");
                }
                this->state = std::move(state);
            }

            const state_ptr &Context::get_state() const noexcept {
                return this->state;
            }

        }
    }
}