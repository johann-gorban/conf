#include "states.hpp"

namespace config {

    namespace processing {

        namespace tokenization {
            State::State(const std::string &name) : debug_info(name) {};

            std::string State::get_name() const noexcept {
                return this->debug_info;
            }

            StartState::StartState() : State("START") {}

            IdentifierState::IdentifierState() : State("IDENTIFIER") {}

            OperatorState::OperatorState() : State("OPERATOR") {}

            ArrayState::ArrayState() : State("ARRAY") {}

            StringState::StringState() : State("STRING") {}

            NumberState::NumberState() : State("NUMBER") {}

            EndState::EndState() : State("END") {}
        }
    }
}