#pragma once

#include "context.hpp"
#include "token.hpp"

namespace config {

    namespace processing {

        namespace tokenization {

            class Context;

            class State {
            public:
                virtual void handle_char(Context &ctx, char c) = 0;
                
                virtual void emit_token(Context &ctx) = 0;

                virtual ~State() = default;
            };

            class StartState : public State {
            public:
                void handle_char(Context &ctx, char c) override;
            
                void emit_token(Context &ctx) override;
            };

            class IdentifierState : public State {
            public:
                void handle_char(Context &ctx, char c) override;

                void emit_token(Context &ctx) override;
            };

            class OperatorState : public State {
            public:
                void handle_char(Context &ctx, char c) override;

                void emit_token(Context &ctx) override;
            };

            class ArrayState : public State {
            public:
                void handle_char(Context &ctx, char c) override;

                void emit_token(Context &ctx) override;
            };

            class StringState : public State {
            public:
                void handle_char(Context &ctx, char c) override;

                void emit_token(Context &ctx) override;
            };

            class NumberState : public State {
            public:
                void handle_char(Context &ctx, char c) override;
                
                void emit_token(Context &ctx) override;
            };

            class EndState : public State {
            public:
                void handle_char(Context &ctx, char c) override;
            
                void emit_token(Context &ctx) override;
            };

            using state_ptr = std::shared_ptr<State>;

        }

    }

}