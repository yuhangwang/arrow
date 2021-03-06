// Copyright (c) 2014-2015 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/ir.hpp"
#include "arrow/generator.hpp"

using arrow::ir::Return;

LLVMValueRef Return::handle(GContext &ctx) noexcept {
  if (!_handle) {
    // Build terminating ret ..
    if (!operand->type->is_unit()) {
      // Get type of enclosing function
      auto top_f = ctx.function_s.top();
      auto result_type = cast<TypeFunction>(top_f->type)->result;

      // Value return
      auto op_handle = ir::transmute(operand, result_type)->value_of(ctx);
      LLVMBuildRet(ctx.irb, op_handle);
    } else {
      // Void return
      LLVMBuildRetVoid(ctx.irb);
    }

    // No value (for return)
    _handle = LLVMGetUndef(LLVMVoidType());
  }

  return nullptr;
}
