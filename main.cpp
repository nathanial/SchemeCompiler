#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include "token.hpp"
#include "lexer.hpp"
#include <boost/shared_ptr.hpp>
#include "parser.hpp"

using namespace std;

void test_sum(){
  char str[] = "(define (sum a b) (+ a b))";
  Tokens tokens;
  scanner(str, strlen(str), &tokens);
  for(unsigned int i = 0; i < tokens.size(); i++){
    cout << *tokens[i] << "\n";
  }
  Parser p(tokens);
  ASTPtr ast = p.parse();
  cout << *ast << endl;
}

int main(int argc, char *argv[]){
  test_sum();
  return 0;
}
