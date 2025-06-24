#pragma once

#include "states.hpp"

#include <unordered_map>
#include <typeindex>
#include <functional>

namespace config {

    namespace processing {

        namespace tokenization {

            class StateFactory {
            private:
                // using creator_function = std::function<state_ptr()>;
                std::unordered_map<std::string, state_ptr> table;
            public:
                StateFactory();

                state_ptr create_start(const std::string &identifier);
            };
        }
    }
}