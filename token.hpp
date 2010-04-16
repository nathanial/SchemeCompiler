#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
using namespace std;
using namespace boost;

enum TokenType {
  LPAREN, RPAREN, SYMBOL, INTEGER, FLOAT
};

class Token;

typedef shared_ptr<Token> TokenPtr;
typedef vector<TokenPtr> Tokens;

class Token {
public:
  TokenType type;
  string value;
  
  explicit Token(TokenType type, string value);
  virtual ~Token();

  static TokenPtr create(TokenType type, string value);
  static TokenPtr create(TokenType type, char *start, char *end);

private:
  Token(const Token& t);
  Token& operator=(const Token& rhs);
};

ostream& operator << (ostream& os, Token& token);

#endif
