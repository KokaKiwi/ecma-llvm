#ifndef ECMA_LLVM_IR_H_
#define ECMA_LLVM_IR_H_

#include "config.h"

#if LLVM_VERSION_NUMBER == 29
#include <llvm/BasicBlock.h>
#include <llvm/Constants.h>
#include <llvm/DerivedTypes.h>
#include <llvm/Function.h>
#include <llvm/Support/IRBuilder.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Type.h>
#include <llvm/Support/TypeBuilder.h>
#include <llvm/Value.h>
#elif LLVM_VERSION_NUMBER == 30
#include <llvm/BasicBlock.h>
#include <llvm/Constants.h>
#include <llvm/DerivedTypes.h>
#include <llvm/Function.h>
#include <llvm/Support/IRBuilder.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Type.h>
#include <llvm/Support/TypeBuilder.h>
#include <llvm/Value.h>
#elif LLVM_VERSION_NUMBER == 31
#include <llvm/BasicBlock.h>
#include <llvm/Constants.h>
#include <llvm/DerivedTypes.h>
#include <llvm/Function.h>
#include <llvm/Support/IRBuilder.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Type.h>
#include <llvm/Support/TypeBuilder.h>
#include <llvm/Value.h>
#elif LLVM_VERSION_NUMBER == 32
#include <llvm/BasicBlock.h>
#include <llvm/Constants.h>
#include <llvm/DerivedTypes.h>
#include <llvm/Function.h>
#include <llvm/IRBuilder.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Type.h>
#include <llvm/TypeBuilder.h>
#include <llvm/Value.h>
#elif LLVM_VERSION_NUMBER == 33
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/TypeBuilder.h>
#include <llvm/IR/Value.h>
#else
#include <llvm/BasicBlock.h>
#include <llvm/Constants.h>
#include <llvm/DerivedTypes.h>
#include <llvm/Function.h>
#include <llvm/Support/IRBuilder.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Type.h>
#include <llvm/Support/TypeBuilder.h>
#include <llvm/Value.h>
#endif

#endif /* ECMA_LLVM_IR_H_ */
