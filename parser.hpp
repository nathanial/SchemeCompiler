#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "token.hpp"
#include <ostream>

using namespace std;

class AST;

typedef map<const char *, const char *> AttributeMap;
typedef shared_ptr<AST> ASTPtr;
typedef vector<ASTPtr> ASTChildren;

enum ASTKind {
  AST_ATOM, 
  AST_SEXP, 
  AST_SYMBOL,
  AST_INTEGER,
  AST_FLOAT,
  AST_ERROR
};

class AST {
private:
  friend ostream& operator << (ostream& os, AST& ast);
  ASTKind kind;
  Tokens tokens;
  AttributeMap attributes;
  ASTChildren children;

public:
  AST(ASTKind kind, Tokens &tokens, AttributeMap &attrs, ASTChildren &children);
  AST(ASTKind kind, Tokens &tokens);
  AST(ASTKind kind);
  AST(ASTKind kind, ASTChildren &children);
  virtual ~AST();
  static ASTPtr create(ASTKind kind, Tokens &tokens, AttributeMap &attrs,
		       ASTChildren &children);
  static ASTPtr create(ASTKind kind, Tokens &tokens);
  static ASTPtr create(ASTKind kind);
  static ASTPtr create(ASTKind kind, ASTChildren &children);

private:
  AST(const AST& t);
  AST& operator=(const AST& rhs);
};

ostream& operator << (ostream& os, AST& ast);

class Parser {
  Tokens tokens;
  unsigned int cursor;
  bool error;
public:
  Parser(Tokens &tokens);
  virtual ~Parser();
  ASTPtr parse();
private:
  bool lparen();
  bool rparen();
  ASTPtr atom();
  bool have_more_tokens();
  TokenType token_type();
};


#endif
