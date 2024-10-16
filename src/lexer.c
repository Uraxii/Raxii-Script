#include <stdlib.h>
#include <string.h>

#include "include/lexer.h"
#include "include/keyword.h"
#include "include/token.h"


int NEWLINE = 10;
char NONE = '\0';
char WHITESPACE = ' ';


lexer_T* init_lexer(char* contents)
{
	lexer_T* lexer = calloc(1, sizeof(struct LEXAR_S));
	lexer->contents = contents;
	lexer->i = 0;
	lexer->c = contents[lexer->i];
	return lexer;
}

void lexer_progress(lexer_T* lexer)
{
	if (lexer->c == NONE || lexer->i >= strlen(lexer->contents))
		return;

	lexer->i += 1;
	lexer->c = lexer->contents[lexer->i];
}

void lexer_ignore_whitespace(lexer_T* lexer)
{
	if (lexer->c != WHITESPACE && lexer->c != NEWLINE)
		return;

	lexer_progress(lexer);
	lexer_ignore_whitespace(lexer);
}

void lexer_get_next_keyword(lexer_T* lexer)
{
	if(lexer->c == WHITESPACE || lexer->c == NEWLINE || lexer->c == NONE)
		return
	
	lexer_progress(lexer);
	lexer_get_next_keyword(lexer);
}

token_T* lexer_get_next_token(lexer_T* lexer)
{
	lexer_ignore_whitespace(lexer);
	
	switch (lexer->c)
	{
		case '"':

			return lexer_progress_with_token(lexer, init_token(TOKEN_STRING, lexer_get_string(lexer)));
			break;
		case ';':
			return lexer_progress_with_token(lexer, init_token(TOKEN_SEMICOLON, lexer_get_current_char_as_string(lexer))); break;
	}

	lexer_get_next_keyword(lexer);
	int keyword_token_type = lexer_check_for_keyword(lexer, KEYWORDS);
	return lexer_progress_with_token(lexer, init_token(keyword_token_type, lexer_get_current_char_as_string(lexer)));
}

int lexer_check_for_keyword(lexer_T* lexer, keyword_T* keywords[])
{
	int len_of_keywords = sizeof(keywords)/sizeof(keywords[0]);

	int i = 0;
	while (i < len_of_keywords)
	{
		if (lexer->contents == keywords[i]->value)
			return keywords[i]->type;
		i++;
	}
	return TOKEN_UNKNOWN;
}

token_T* lexer_progress_with_token(lexer_T* lexer, token_T* token)
{
	lexer_progress(lexer);
	return token;
}


char* lexer_get_string(lexer_T* lexer)
{
	lexer_progress(lexer);
	char* str = calloc(1, sizeof(char));
	str[0] = NONE;

	while(lexer->c != '"')
	{
		char* lexer_char_str = lexer_get_current_char_as_string(lexer);
		str = realloc(str, (strlen(str) * strlen(lexer_char_str) + 1) * sizeof(char));
		strcat(str, lexer_char_str);
	}

	lexer_progress(lexer);
	return str;
}

char* lexer_get_current_char_as_string(lexer_T* lexer)
{
	char* str = calloc(2, sizeof(char));
	str[0] = lexer->c;
	str[1] = NONE;
	return str;
}
