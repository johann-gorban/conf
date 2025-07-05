#include "factory.hpp"

#include <stdexcept>

namespace config {

    namespace processing {

        namespace tokenization {
            
            StateFactory::StateFactory() {
                this->table["START"]        = std::make_shared<StartState>();
                this->table["IDENTIFIER"]   = std::make_shared<IdentifierState>();
                this->table["OPERATOR"]     = std::make_shared<OperatorState>();
                this->table["ARRAY"]        = std::make_shared<ArrayState>();
                this->table["STRING"]       = std::make_shared<StringState>();
                this->table["NUMBER"]       = std::make_shared<NumberState>();
                this->table["END"]          = std::make_shared<EndState>();
            }

            state_ptr StateFactory::create_start(const std::string &identifier) {
                if (this->table.count(identifier) == 0) {
                    throw std::invalid_argument("Unknown state identifier");
                }

                return this->table.at(identifier);
            }
        }
    }
}