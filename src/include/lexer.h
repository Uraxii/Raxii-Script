#ifndef LEXER_H
#define LEXER_H

#include "token.h"


typedef struct LEXAR_S
{
	char c;
	unsigned int i;
	char* contents;
} lexer_T;

typedef struct KEYWORD_S
{
	int type;
	char* value;
} keyword_T;


void set_keywords();

lexer_T* init_lexer(char* contents);

void lexer_progress(lexer_T* lexer);

void lexer_ignore_whitespace(lexer_T* lexer);

char* lexer_get_next_word(lexer_T* lexer);

int check_for_keyword(char* word);

char* lexer_get_string(lexer_T* lexer);

token_T* lexer_get_id(lexer_T* lexer);

token_T* lexer_get_next_token(lexer_T* lexer);

char* lexer_get_current_char_as_string(lexer_T* lexer);

token_T* lexer_progress_with_token(lexer_T* lexer, token_T* token);

keyword_T* lexer_progress_with_keyword(lexer_T* lexer, keyword_T* keyword);
#endif
