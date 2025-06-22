#include "lexer.hpp"

#include "context.hpp"
#include "states.hpp"

namespace config {

    namespace processing {

        namespace tokenization {

            std::vector<config::token_ptr> Lexer::tokenize(const std::string &s) const {
                Context ctx(std::make_shared<StartState>);

                for (char c : s) {
                    const auto &state = ctx.get_state();
                    state->handle_char(ctx, c);
                }

                const auto &end_state = ctx.get_state();
                end_state->emit_token(ctx);

                return ctx.get_tokens();
            }

        }
    }
}