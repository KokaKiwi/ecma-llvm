
// Category
ECMA_ARG(llvm::cl::OptionCategory, ecmaOptions, "ecmac options");

// Input
ECMA_ARG(llvm::cl::list<std::string>, input, llvm::cl::Positional, llvm::cl::desc("<input files>"), llvm::cl::cat(ecmaOptions));

// Parse
ECMA_ARG(llvm::cl::opt<bool>, parseOnly, "P", llvm::cl::desc("Run the parse phase."), llvm::cl::cat(ecmaOptions));

// Compile
ECMA_ARG(llvm::cl::opt<bool>, compileOnly, "S", llvm::cl::desc("Compile only; do not assemble or link"), llvm::cl::cat(ecmaOptions));
ECMA_ARG(llvm::cl::opt<bool>, llvmOutput, "emit-llvm", llvm::cl::desc("Produce an LLVM assembly file if used with -S option; produce an LLVM bitcode file otherwise"), llvm::cl::cat(ecmaOptions));

// Output
ECMA_ARG(llvm::cl::opt<std::string>, output, "o", llvm::cl::desc("Write output to <filename>"), llvm::cl::value_desc("filename"), llvm::cl::cat(ecmaOptions));
ECMA_ARG(llvm::cl::alias, outputAlias, "output", llvm::cl::desc("Alias for -o"), llvm::cl::aliasopt(output), llvm::cl::cat(ecmaOptions));

// Common
ECMA_ARG(llvm::cl::list<std::string>, compilerFlags, "Z", llvm::cl::desc("Internal compiler flags."), llvm::cl::cat(ecmaOptions));
ECMA_ARG(llvm::cl::opt<bool>, noColor, "no-color", llvm::cl::desc("Disable colored output."), llvm::cl::cat(ecmaOptions));
