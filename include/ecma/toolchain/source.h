#ifndef ECMA_TOOLCHAIN_SOURCE_H_
#define ECMA_TOOLCHAIN_SOURCE_H_

#include <string>
#include <fstream>
#include "ecma/ast/stmt/block.h"

namespace ecma
{
    namespace toolchain
    {
        class Source
        {
        public:
            inline Source(const std::string &name, const std::string &source): m_name(name), m_source(source) {}

            ast::stmt::Block *parse(void) const;

            inline const std::string &name(void) const
            {
                return m_name;
            }
            inline Source &name(const std::string &name)
            {
                m_name = name;
                return *this;
            }

            static Source fromString(const std::string &source);
            static Source fromFile(const std::string &path);
            static Source fromStream(std::istream &stream);

        private:
            std::string m_name;
            std::string m_source;
        };
    }
}

#endif /* ECMA_TOOLCHAIN_SOURCE_H_ */
