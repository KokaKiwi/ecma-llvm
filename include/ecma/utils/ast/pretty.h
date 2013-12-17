#ifndef ECMA_UTILS_AST_PRETTY_H_
#define ECMA_UTILS_AST_PRETTY_H_

#include <iostream>
#include "ecma/ast/tools/visitor.h"
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace utils
    {
        namespace ast
        {
            class PrettyPrintVisitor: public ecma::ast::tools::Visitor
            {
            public:
                PrettyPrintVisitor(std::ostream &stream)
                    : m_stream(stream)
                    , m_indent(0)
                {}

                PrettyPrintVisitor()
                    : PrettyPrintVisitor(std::cerr)
                {}

                // AST
                virtual inline void visit(ecma::ast::Module &module)
                {
                    for (auto it = module.statements().begin(); it != module.statements().end(); ++it)
                    {
                        (*it)->accept(*this);
                    }
                }

                // Statement
                /// Try/Catch
                virtual inline void visit(ecma::ast::stmt::Try &stmt)
                {
                    line() << "try {" << std::endl;

                    auto block = stmt.block();

                    m_indent += 4;
                    for (auto it = block->statements().begin(); it != block->statements().end(); ++it)
                    {
                        (*it)->accept(*this);
                    }
                    m_indent -= 4;

                    line() << "}";

                    auto catch_action = stmt.catch_action();
                    if (catch_action != nullptr)
                    {
                        raw() << " catch(" << catch_action->name() << ") {" << std::endl;

                        auto action = catch_action->action();

                        m_indent += 4;
                        for (auto it = action->statements().begin(); it != action->statements().end(); ++it)
                        {
                            (*it)->accept(*this);
                        }
                        m_indent -= 4;


                        line() << "}";
                    }

                    auto finally_action = stmt.finally_action();
                    if (finally_action != nullptr)
                    {
                        raw() << " finally {" << std::endl;

                        auto action = finally_action->action();

                        m_indent += 4;
                        for (auto it = action->statements().begin(); it != action->statements().end(); ++it)
                        {
                            (*it)->accept(*this);
                        }
                        m_indent -= 4;

                        line() << "}";
                    }

                    raw() << std::endl;
                }

                // Misc
                inline std::ostream &line() const
                {
                    raw() << spaces();
                    return raw();
                }

                inline std::ostream &raw() const
                {
                    return m_stream;
                }

            private:
                inline const std::string spaces() const
                {
                    std::string indent(m_indent, ' ');
                    return indent;
                }

                std::ostream &m_stream;
                uint m_indent;
            };
        }
    }
}

#endif /* ECMA_UTILS_AST_PRETTY_H_ */
