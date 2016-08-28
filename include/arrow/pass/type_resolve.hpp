// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#ifndef ARROW_TYPE_RESOLVE_H
#define ARROW_TYPE_RESOLVE_H

#include <memory>
#include <string>
#include <unordered_map>

#include "arrow/pass.hpp"

namespace arrow {
namespace pass {

class TypeResolve : public Pass {
 public:
  TypeResolve(GContext& ctx);

  ptr<ir::Type> run(ptr<ast::Type>);

 private:
  ptr<ir::Type> handle_type_name(ptr<ast::TypeName>);

  // Built-in types
  std::unordered_map<std::string, ptr<ir::Type>> _types;
};

}  // namespace back
}  // namespace arrow

#endif  // ARROW_TYPE_RESOLVE_H