#include "lexer.hpp"

#include "context.hpp"
#include "states.hpp"

namespace config {

    namespace processing {

        namespace tokenization {

            std::vector<config::token_ptr> Lexer::tokenize(const std::string &s) const {
                Context ctx;

                auto start = std::make_shared<StartState>();
                ctx.set_state(std::move(start));

                for (auto c : s) {
                    auto state = ctx.get_state();
                    state->handle_char(ctx, c);
                }

                return ctx.get_tokens();
            }

        }
    }
}