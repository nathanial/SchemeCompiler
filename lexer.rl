#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include "token.hpp"

using namespace std;

%%{
	machine schang;

	newline = '\n' @{curline += 1;};
	any_count_line = any | newline;

	main := |*

	# Alpha numeric characters or underscore.
	alnum_u = alnum | '_';

	# Alpha characeters or underscore.
	alpha_u = alpha | [_+-=/];

	'(' { 
	    tokens->push_back(Token::create(LPAREN, ts,te));
	};

	')' {
	    tokens->push_back(Token::create(RPAREN, ts,te));
	};
	
	alpha_u alnum_u* {
		tokens->push_back(Token::create(SYMBOL, ts,te));
	};

	# Whitespace is standard ws, newlines and control codes.
	any_count_line - 0x21..0x7e;

	digit+ {
		tokens.push_back(Token::create(INTEGER,ts,te));
	};

	digit+ '.' digit+ {
		tokens->push_back(Token::create(FLOAT,ts,te));
	};

	*|;
}%%

%% write data nofinal;


void scanner(char *str, int len, Tokens *tokens)
{
	int cs, act, curline = 1;
	char *ts, *te = 0;

	%% write init;
	char *p = str;
	char *pe =  p + len + 1;
	char *eof = 0;
	%% write exec;
	if ( cs == schang_error ) {
	   fprintf(stderr, "PARSE ERROR\n" );
	}
}