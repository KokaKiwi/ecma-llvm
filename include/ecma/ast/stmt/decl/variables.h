#ifndef VARIABLES_H_
#define VARIABLES_H_

#include <vector>
#include <memory>
#include "ecma/ast/statement.h"
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace decl
            {
                class Variables: public ast::Statement
                {
                public:
                    class Variable;

                    inline Variables() {}

                    inline std::vector<Variable *> &vars(void)
                    {
                        return m_vars;
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::vector<Variable *> m_vars;
                };

                class Variables::Variable
                {
                public:
                    inline Variable(const std::string &name, ast::Expression *initializer = nullptr): m_name(name), m_initializer(initializer) {}

                    inline const std::string name(void) const
                    {
                        return m_name;
                    }
                    inline Variable &name(std::string name)
                    {
                        m_name = name;
                        return *this;
                    }

                    inline ast::Expression *initializer(void) const
                    {
                        return m_initializer.get();
                    }
                    inline Variable &initializer(ast::Expression *initializer)
                    {
                        m_initializer.reset(initializer);
                        return *this;
                    }
                    inline ast::Expression *takeInitialize(void)
                    {
                        return m_initializer.release();
                    }

                private:
                    std::string m_name;
                    std::unique_ptr<ast::Expression> m_initializer;
                };
            }
        }
    }
}

#endif /* VARIABLES_H_ */
