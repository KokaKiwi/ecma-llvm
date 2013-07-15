#include <cxxtest/TestSuite.h>
#include "ecma/toolchain/source.h"
#include "ecma/parser/exception.h"

using namespace ecma;
using namespace ecma::ast;
using namespace ecma::parser;
using namespace ecma::toolchain;

class TestBasic: public CxxTest::TestSuite
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
        Source source = Source::fromString("var i;");
        stmt::Block *program = source.parse();

        TS_ASSERT_DIFFERS(program, nullptr);
        TS_ASSERT_EQUALS(program->statements().size(), 1);

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
