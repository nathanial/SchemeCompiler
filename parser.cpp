#include "parser.hpp"
#include <map>
#include <vector>
#include "token.hpp"
#include <ostream>
#include <iostream>

AST::AST(ASTKind kind, Tokens &tokens, AttributeMap &attrs, ASTChildren &children){
  this->kind = kind;
  this->tokens = tokens;
  this->attributes = attrs;
  this->children = children;
}

AST::AST(ASTKind kind, Tokens &tokens){
  this->kind = kind;
  this->tokens = tokens;
}

AST::AST(ASTKind kind){
  this->kind = kind;
}

AST::AST(ASTKind kind, ASTChildren &children){
  this->kind = kind;
  this->children = children;
}

AST::~AST(){
}

ASTPtr AST::create(ASTKind kind, Tokens &tokens, AttributeMap &attrs, ASTChildren &children){
  return ASTPtr(new AST(kind, tokens, attrs, children));
}

ASTPtr AST::create(ASTKind kind, Tokens &tokens){
  return ASTPtr(new AST(kind, tokens));
}

ASTPtr AST::create(ASTKind kind){
  return ASTPtr(new AST(kind));
}

ASTPtr AST::create(ASTKind kind, ASTChildren &children){
  return ASTPtr(new AST(kind, children));
}

ostream& operator << (ostream& os, AST& ast){
  switch(ast.kind){
  case AST_ERROR: os << "ERROR"; break;
  case AST_ATOM: os << "ATOM"; break;
  case AST_SEXP: os << "SEXP"; break;
  case AST_SYMBOL: os << "SYMBOL"; break;
  case AST_INTEGER: os << "INTEGER"; break;
  case AST_FLOAT: os << "FLOAT"; break;
  }
  cout << "(";
  for(unsigned int i = 0; i < ast.children.size(); i++){
    cout << *ast.children[i];
    if(i < ast.children.size() - 1){
      cout << ",";
    }
  }
  for(unsigned int i = 0; i < ast.tokens.size(); i++){
    cout << ast.tokens[i]->value;
    if(i < ast.tokens.size() - 1){
      cout << ",";
    }
  }
  cout << ")";
  return os;
}

Parser::Parser(Tokens &tokens){
  this->tokens = tokens;
  this->cursor = 0;
  this->error = false;
}

Parser::~Parser(){
  
}

ASTPtr Parser::parse(){
  if(lparen()){
    ASTChildren sexp_members;
    error = false;
    while(!error){
      ASTPtr result = parse();
      sexp_members.push_back(result);
    }
    sexp_members.pop_back();
    error = false;
    if(!rparen()) goto error;
    return AST::create(AST_SEXP, sexp_members);
  }
  else {
    return atom();
  }
 error:
  Tokens t;
  error = true;
  return AST::create(AST_ERROR, t);
}

bool Parser::lparen(){
  if(have_more_tokens() && token_type() == LPAREN){
    cursor++;
    return true;
  } else {
    return false;
  }
}

bool Parser::rparen(){
  if(have_more_tokens() && token_type() == RPAREN){
    cursor++;
    return true;
  } else {
    return false;
  }
}

ASTPtr Parser::atom(){
  Tokens empty;
  if(have_more_tokens()){
    ASTPtr result;
    Tokens atoks;
    atoks.push_back(tokens[cursor]);
    switch(token_type()){
    case SYMBOL: 
      result = AST::create(AST_SYMBOL, atoks);
      break;
    case FLOAT: 
      result = AST::create(AST_FLOAT, atoks);
      break;
    case INTEGER: 
      result = AST::create(AST_INTEGER, atoks);
      break;
    default:
      goto error;
    }
    cursor++;
    return result;
  } 
 error:
  error = true;
  return AST::create(AST_ERROR, empty);
}

bool Parser::have_more_tokens(){
  return cursor < tokens.size();
}

TokenType Parser::token_type(){
  return tokens[cursor]->type;
}
