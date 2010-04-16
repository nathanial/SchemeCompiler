#include "parser.hpp"
#include <map>
#include <vector>
#include "token.hpp"

AST::AST(ASTKind kind, Tokens &tokens, AttributeMap &attrs) {
  this->kind = kind;
  this->tokens = &tokens;
  this->attributes = &attrs;
}

AST::~AST(){
  delete tokens;
  delete attributes;
}
