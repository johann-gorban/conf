#pragma once

#include <memory>
#include <string>

namespace config {

    namespace processing {

        namespace tokenization {

            class Context;

            class State {
            private:
                const std::string debug_info;
            public:
                explicit State(const std::string &name);

                std::string get_name() const noexcept;

                virtual void handle_char(Context &ctx, char c) = 0;
                
                virtual void emit_token(Context &ctx) = 0;

                virtual ~State() = default;
            };

            class StartState : public State {
            public:
                StartState();

                void handle_char(Context &ctx, char c) override;
            
                void emit_token(Context &ctx) override;
            };

            class IdentifierState : public State {
            public:
                IdentifierState();

                void handle_char(Context &ctx, char c) override;

                void emit_token(Context &ctx) override;
            };

            class OperatorState : public State {
            public:
                OperatorState();

                void handle_char(Context &ctx, char c) override;

                void emit_token(Context &ctx) override;
            };

            class ArrayState : public State {
            public:
                ArrayState();

                void handle_char(Context &ctx, char c) override;

                void emit_token(Context &ctx) override;
            };

            class StringState : public State {
            public:
                StringState();

                void handle_char(Context &ctx, char c) override;

                void emit_token(Context &ctx) override;
            };

            class NumberState : public State {
            public:
                NumberState();

                void handle_char(Context &ctx, char c) override;
                
                void emit_token(Context &ctx) override;
            };

            class EndState : public State {
            public:
                EndState();

                void handle_char(Context &ctx, char c) override;
            
                void emit_token(Context &ctx) override;
            };

            using state_ptr = std::shared_ptr<State>;

        }

    }

}