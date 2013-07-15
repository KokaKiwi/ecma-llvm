#!/bin/bash

__update_llvm_header()
{
    src="$1"
    header="$2"

    sed -i "s/llvm\/${header}/llvm\/IR\/${header}/g" ${src}
}

__update_llvm()
{
    src="$1"

    echo "Updating ${src}"

    __update_llvm_header ${src} "BasicBlock.h"
    __update_llvm_header ${src} "Constants.h"
    __update_llvm_header ${src} "DerivedTypes.h"
    __update_llvm_header ${src} "Function.h"
    __update_llvm_header ${src} "IRBuilder.h"
    __update_llvm_header ${src} "LLVMContext.h"
    __update_llvm_header ${src} "Module.h"
    __update_llvm_header ${src} "Type.h"
    __update_llvm_header ${src} "TypeBuilder.h"
    __update_llvm_header ${src} "Value.h"
}

SRCDIRS=(compiler ecmac include parser runtime)
SRCS=$(find ${SRCDIRS[@]} -type f -name "*.cpp" -or -name "*.h")

for src in ${SRCS[@]}; do
    __update_llvm ${src}
done
