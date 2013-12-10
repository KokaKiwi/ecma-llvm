#!/bin/bash
HERE=$(dirname $0)

set -e

# Env
if [[ "$DEBUG" = "1" ]]; then
    DEBUG_FLAGS="-d"
else
    DEBUG_FLAGS=""
fi

# Required paths
PYTHON=$(which python3)

# Project paths
INCLUDE_DIR="${HERE}/include"
PARSER_DIR="${HERE}/parser"
TOOLS_DIR="${HERE}/tools"

# Misc paths
AST_FILENAME="ecma.ast"

ZINC_SCRIPT="${TOOLS_DIR}/zinc/zinc.py"
AST_FILE="${HERE}/${AST_FILENAME}"

zinc() {
    ${PYTHON} ${ZINC_SCRIPT} ${DEBUG_FLAGS} --ast ${AST_FILE} $*
}

# Generate lexer
echo "Generate lexer..."
LEXER_SRC="${PARSER_DIR}/lex/lexer.tpl.rl"
LEXER_DST="${PARSER_DIR}/lex/lexer.rl"
zinc gen_lexer ${LEXER_SRC} ${LEXER_DST}

# Generate types
echo "Generate types..."
TYPES_SRC="${INCLUDE_DIR}/ecma/lex/types.tpl.h"
TYPES_DST="${INCLUDE_DIR}/ecma/lex/types.h"
zinc gen_types ${TYPES_SRC} ${TYPES_DST}

# Generate parser
echo "Generate parser..."
PARSER_SRC="${PARSER_DIR}/parser/lemon-parser.tpl.lm"
PARSER_DST="${PARSER_DIR}/parser/lemon-parser.lm"
zinc gen_parser ${PARSER_SRC} ${PARSER_DST}

# Generate AST headers
echo "Generate AST headers..."
AST_INCLUDE_DIR="${INCLUDE_DIR}/ecma/ast"
AST_NAMESPACE="ecma::ast"
rm -rf ${AST_INCLUDE_DIR}
mkdir -p ${AST_INCLUDE_DIR}
zinc gen_ast --namespace ${AST_NAMESPACE} ${AST_INCLUDE_DIR}
