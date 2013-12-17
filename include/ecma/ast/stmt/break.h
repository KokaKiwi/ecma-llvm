#ifndef ECMA_AST_STMT_BREAK_H_
#define ECMA_AST_STMT_BREAK_H_

#include <string>
#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class Break: public Statement
            {
                public:
                    inline Break()
                        : Statement()
                    {
                    }
                    virtual inline ~Break()
                    {
                    }

                    inline const std::string *name() const
                    {
                        return m_name.get();
                    }
                    inline Break &name(std::string *name)
                    {
                        m_name.reset(name);
                        return *this;
                    }
                    inline std::string *take_name()
                    {
                        return m_name.release();
                    }

                    virtual inline void accept(tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<std::string> m_name;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_BREAK_H_ */
