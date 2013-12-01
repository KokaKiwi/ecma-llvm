#include <cxxtest/TestSuite.h>
#include "ecma/toolchain/source.h"
#include "ecma/parser/exception.h"
#include "ecma/ast/ast.h"

using namespace ecma;
using namespace ecma::ast;
using namespace ecma::parser;
using namespace ecma::toolchain;

class TestParser: public CxxTest::TestSuite
{
public:
    void test_source_empty()
    {
        Source source = Source::fromString("");
        stmt::Block *program = source.parse();

        TS_ASSERT_DIFFERS(program, nullptr);
        TS_ASSERT_EQUALS(program->statements().size(), 0);

        delete program;
    }

    void test_source_vardecl()
    {
        Source source = Source::fromString("var toto = 125;");
        stmt::Block *program = source.parse();

        TS_ASSERT_DIFFERS(program, nullptr);
        TS_ASSERT_EQUALS(program->statements().size(), 1);

        stmt::decl::Variables *vardecls = static_cast<stmt::decl::Variables *>(program->statements()[0]);
        stmt::decl::Variables::Variable *var = vardecls->vars()[0];
        TS_ASSERT_EQUALS(var->name(), "toto");

        expr::literal::Integer *value = static_cast<expr::literal::Integer *>(var->initializer());
        TS_ASSERT_EQUALS(value->value(), 125);

        delete program;
    }

    void test_parsing_error()
    {
        Source source = Source::fromString("var i = ;");
        stmt::Block *program;

        TS_ASSERT_THROWS(program = source.parse(), Exception);

        // delete program;
    }
};
