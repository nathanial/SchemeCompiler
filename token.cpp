#include "token.hpp"
#include <ostream>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <sstream>

static int token_count = 0;

static string token_to_str(char *start, char *end){
       stringstream tok;
       int len = end - start;
       for(int i = 0; i < len; i++){
       	  tok << *(start + i);
       }      
       return tok.str();
}


ostream& operator << (ostream& os, Token& token){
  os << "Token(";
  switch(token.type){
  case LPAREN: os << "LPAREN"; break;
  case RPAREN: os << "RPAREN"; break;
  case SYMBOL: os << "SYMBOL"; break;
  case INTEGER: os << "INTEGER"; break;
  case FLOAT: os << "FLOAT"; break;
  default:
    throw "Invalid Token Type";
  }
  os << ",'" << token.value << "')";
  return os;
}

Token::Token(TokenType type, string value): type(type), value(value) {
  cout << "Token Created: " << ++token_count <<  endl;
}

Token::~Token(){
  cout << "Token Deleted: " << --token_count << endl;
}

TokenPtr Token::create(TokenType type, string value){
  return TokenPtr(new Token(type, value));
}

TokenPtr Token::create(TokenType type, char *start, char *end){
  return Token::create(type, token_to_str(start, end));
}
