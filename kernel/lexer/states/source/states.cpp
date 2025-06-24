#include "states.hpp"

namespace config {

    namespace processing {

        namespace tokenization {
            State::State(const std::string &identifier) : id(identifier) {};

            std::string State::get_id() const noexcept {
                return this->id;
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