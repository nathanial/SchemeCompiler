#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <vector>
#include "token.hpp"

using namespace std;

typedef map<const char *, const char *> AttributeMap;

enum ASTKind {
  ATOM, SEXP
};

class AST {
private:
  ASTKind kind;
  Tokens *tokens;
  AttributeMap *attributes;

public:
  AST(ASTKind kind, Tokens &tokens, AttributeMap &attrs);
  virtual ~AST();
};

#endif
