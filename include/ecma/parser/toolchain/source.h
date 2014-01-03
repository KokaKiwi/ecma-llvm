#ifndef ECMA_TOOLCHAIN_SOURCE_H_
#define ECMA_TOOLCHAIN_SOURCE_H_

#include <string>
#include <fstream>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace parser
    {
        namespace toolchain
        {
            class Source
            {
            public:
                Source(const std::string &name, const std::string &source);

                ast::Module *parse(bool debug = false) const;

                void updateEnv() const;

                inline const std::string &name() const
                {
                    return m_name;
                }
                inline Source &name(const std::string &name)
                {
                    m_name = name;
                    return *this;
                }

                inline const std::string &source() const
                {
                    return m_source;
                }

                static Source *fromString(const std::string &source, const std::string &name = "{inline}");
                static Source *fromFile(const std::string &path);
                static Source *fromStream(std::istream &stream, const std::string &name = "{stream}");

            private:
                std::string m_name;
                std::string m_source;
            };
        }
    }
}

#endif /* ECMA_TOOLCHAIN_SOURCE_H_ */
