#ifndef LEXER_H
#define LEXER_H
#include "keyword.h"
#include "token.h"

typedef struct LEXAR_S
{
	char c;
	unsigned int i;
	char* contents;
} lexer_T;

lexer_T* init_lexer(char* contents);

void lexer_progress(lexer_T* lexer);

void lexer_ignore_whitespace(lexer_T* lexer);

void lexer_get_next_keyword(lexer_T* lexer);

int lexer_check_for_keyword(lexer_T* lexer, keyword_T* keywords[]);

char* lexer_get_string(lexer_T* lexer);

char* lexer_get_current_char_as_string(lexer_T* lexer);

token_T* lexer_progress_with_token(lexer_T* lexer, token_T* token);
#endif
