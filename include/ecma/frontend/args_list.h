
// Input
ECMA_ARG(llvm::cl::list<std::string>, input, llvm::cl::Positional, llvm::cl::desc("<input files>"));

// Parse
ECMA_ARG(llvm::cl::opt<bool>, parseOnly, "P", llvm::cl::desc("Run the parse phase."));

// Compile
ECMA_ARG(llvm::cl::opt<bool>, compileOnly, "S", llvm::cl::desc("Compile only; do not assemble or link"));
ECMA_ARG(llvm::cl::opt<bool>, llvmOutput, "emit-llvm", llvm::cl::desc("Produce an LLVM assembly file if used with -S option; produce an LLVM bitcode file otherwise"));

// Output
ECMA_ARG(llvm::cl::opt<std::string>, output, "o", llvm::cl::desc("Write output to <filename>"), llvm::cl::value_desc("filename"));
ECMA_ARG(llvm::cl::alias, outputAlias, "output", llvm::cl::desc("Alias for -o"), llvm::cl::aliasopt(output));

// Common
ECMA_ARG(llvm::cl::list<std::string>, compilerFlags, "Z", llvm::cl::desc("Internal compiler flags."));
ECMA_ARG(llvm::cl::opt<bool>, noColor, "no-color", llvm::cl::desc("Disable colored output."));
