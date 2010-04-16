
#line 1 "lexer.rl"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include "token.hpp"

using namespace std;


#line 49 "lexer.rl"



#line 19 "lexer.c"
static const char _schang_actions[] = {
	0, 1, 1, 1, 2, 1, 3, 1, 
	4, 1, 5, 1, 6, 1, 7, 1, 
	8, 1, 9, 2, 0, 6
};

static const char _schang_key_offsets[] = {
	0, 0, 2, 24, 31, 39
};

static const char _schang_trans_keys[] = {
	48, 57, 10, 40, 41, 95, 33, 42, 
	43, 47, 48, 57, 58, 61, 62, 64, 
	65, 90, 91, 96, 97, 122, 123, 126, 
	95, 48, 57, 65, 90, 97, 122, 46, 
	95, 48, 57, 65, 90, 97, 122, 48, 
	57, 0
};

static const char _schang_single_lengths[] = {
	0, 0, 4, 1, 2, 0
};

static const char _schang_range_lengths[] = {
	0, 1, 9, 3, 3, 1
};

static const char _schang_index_offsets[] = {
	0, 0, 2, 16, 21, 27
};

static const char _schang_indicies[] = {
	1, 0, 3, 4, 6, 7, 5, 7, 
	8, 7, 5, 7, 5, 7, 5, 2, 
	7, 7, 7, 7, 9, 10, 7, 8, 
	7, 7, 9, 1, 11, 0
};

static const char _schang_trans_targs[] = {
	2, 5, 2, 2, 2, 0, 2, 3, 
	4, 2, 1, 2
};

static const char _schang_trans_actions[] = {
	17, 0, 11, 19, 7, 0, 9, 0, 
	5, 13, 0, 15
};

static const char _schang_to_state_actions[] = {
	0, 0, 1, 0, 0, 0
};

static const char _schang_from_state_actions[] = {
	0, 0, 3, 0, 0, 0
};

static const char _schang_eof_trans[] = {
	0, 1, 0, 10, 10, 12
};

static const int schang_start = 2;
static const int schang_error = 0;

static const int schang_en_main = 2;


#line 52 "lexer.rl"


void scanner(char *str, int len, Tokens *tokens)
{
	int cs, act, curline = 1;
	char *ts, *te = 0;

	
#line 95 "lexer.c"
	{
	cs = schang_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 60 "lexer.rl"
	char *p = str;
	char *pe =  p + len + 1;
	char *eof = 0;
	
#line 108 "lexer.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_acts = _schang_actions + _schang_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 2:
#line 1 "lexer.rl"
	{ts = p;}
	break;
#line 129 "lexer.c"
		}
	}

	_keys = _schang_trans_keys + _schang_key_offsets[cs];
	_trans = _schang_index_offsets[cs];

	_klen = _schang_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _schang_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _schang_indicies[_trans];
_eof_trans:
	cs = _schang_trans_targs[_trans];

	if ( _schang_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _schang_actions + _schang_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 14 "lexer.rl"
	{curline += 1;}
	break;
	case 3:
#line 1 "lexer.rl"
	{te = p+1;}
	break;
	case 4:
#line 25 "lexer.rl"
	{te = p+1;{ 
	    tokens->push_back(Token::create(LPAREN, ts,te));
	}}
	break;
	case 5:
#line 29 "lexer.rl"
	{te = p+1;{
	    tokens->push_back(Token::create(RPAREN, ts,te));
	}}
	break;
	case 6:
#line 38 "lexer.rl"
	{te = p+1;}
	break;
	case 7:
#line 33 "lexer.rl"
	{te = p;p--;{
		tokens->push_back(Token::create(SYMBOL, ts,te));
	}}
	break;
	case 8:
#line 44 "lexer.rl"
	{te = p;p--;{
		tokens->push_back(Token::create(FLOAT,ts,te));
	}}
	break;
	case 9:
#line 33 "lexer.rl"
	{{p = ((te))-1;}{
		tokens->push_back(Token::create(SYMBOL, ts,te));
	}}
	break;
#line 237 "lexer.c"
		}
	}

_again:
	_acts = _schang_actions + _schang_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 1:
#line 1 "lexer.rl"
	{ts = 0;}
	break;
#line 250 "lexer.c"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _schang_eof_trans[cs] > 0 ) {
		_trans = _schang_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

#line 64 "lexer.rl"
	if ( cs == schang_error ) {
	   fprintf(stderr, "PARSE ERROR\n" );
	}
}