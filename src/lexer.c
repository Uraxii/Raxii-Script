#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/lexer.h"
#include "include/token.h"


int NEWLINE = 10;
char NONE = '\0';
char WHITESPACE = ' ';

keyword_T* KEYWORDS[4];


keyword_T* init_keyword(int type, char* data)
{
	keyword_T* keyword_T = calloc(1, sizeof(struct KEYWORD_S));
	keyword_T->type = type;
	keyword_T->value = data;

	//printf("Created keyword: %d, %s", type, data);
	
	return keyword_T;
}

void set_keywords()
{
	KEYWORDS[0] = init_keyword(TOKEN_KW_SET, "set");
	KEYWORDS[1] = init_keyword(TOKEN_KW_TO, "to");
	KEYWORDS[2] = init_keyword(TOKEN_KW_STRING, "str");
	KEYWORDS[3] = init_keyword(TOKEN_KW_UINT8, "int");
}


lexer_T* init_lexer(char* contents)
{
	//printf("Creating lexer...\n");
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
	//printf("lexer->c: %c\n", lexer->c);
}

void lexer_ignore_whitespace(lexer_T* lexer)
{
	//printf("Ignoring whitespace...\n");
	if (lexer->c != WHITESPACE && lexer->c != NEWLINE)
		return;

	lexer_progress(lexer);
	lexer_ignore_whitespace(lexer);
}

char* lexer_get_string(lexer_T* lexer)
{
	lexer_progress(lexer);
	char* str = calloc(1, sizeof(char));
	str[0] = NONE;

	while(lexer->c != '"')
	{
		char* lexer_char_str = lexer_get_current_char_as_string(lexer);
		str = realloc(str, (strlen(str) + strlen(lexer_char_str) + 1) * sizeof(char));
		strcat(str, lexer_char_str);
		lexer_progress(lexer);
	}

	lexer_progress(lexer); // Ignore closing "
	return str;
}

token_T* lexer_get_id(lexer_T* lexer)
{
	
}

char* lexer_get_next_word(lexer_T* lexer)
{
	//printf("Getting word...\n");

	char* str = calloc(1, sizeof(char));
	str[0] = NONE;

	while(lexer->c != WHITESPACE && lexer->c != NEWLINE && lexer->c != NONE)
	{
		char* lexer_char_str = lexer_get_current_char_as_string(lexer);
		str = realloc(str, (strlen(str) + strlen(lexer_char_str) + 1) * sizeof(char));
		strcat(str, lexer_char_str);
		lexer_progress(lexer);
	}

	return str;
}

int check_for_keyword(char* word)
{
	//printf("Checking for keyword [%s]...\n", word);

	int size_of_keywords = sizeof(KEYWORDS)/sizeof(KEYWORDS[0]);
	if (size_of_keywords == 0)
	{
		fprintf(stderr, "Size of keywords is 0! Exiting...\n");
		exit(EXIT_FAILURE);
	}
	
	//printf("Size of keywords:%d\n", size_of_keywords);

	int i = 0;
	while (i < size_of_keywords)
	{
		//printf("Checking if [%s] == [%s]\n", word, KEYWORDS[i]->value);
		if (strcmp(KEYWORDS[i]->value, word) == 0)
			return KEYWORDS[i]->type;
		i++;
	}
	return TOKEN_UNKNOWN;
}

int check_for_symbol(char* word)
{
	//printf("Checking for symbol [%s]...\n", word);
}

token_T* lexer_get_next_token(lexer_T* lexer)
{
	lexer_ignore_whitespace(lexer);

	//printf("Getting next token (lexer->c: %c)...\n", lexer->c);
	
	switch (lexer->c)
	{
		case '"':
			return lexer_progress_with_token(lexer, init_token(TOKEN_STRING, lexer_get_string(lexer)));
			break;
		case ';':
			return lexer_progress_with_token(lexer, init_token(TOKEN_SEMICOLON, lexer_get_current_char_as_string(lexer)));
			break;
	}

	char* word = lexer_get_next_word(lexer);
	int word_token_type = check_for_keyword(word);
	if (word_token_type != TOKEN_UNKNOWN)
		return lexer_progress_with_token(lexer, init_token(word_token_type, word));

	if(lexer->c != NONE)
		return init_token(TOKEN_SYMBOL, word);

	return lexer_progress_with_token(lexer, init_token(TOKEN_END, lexer_get_current_char_as_string(lexer)));
}

token_T* lexer_progress_with_token(lexer_T* lexer, token_T* token)
{
	lexer_progress(lexer);
	return token;
}

keyword_T* lexer_progress_with_keyword(lexer_T* lexer, keyword_T* keyword)
{
	lexer_progress(lexer);
	return keyword;
}

char* lexer_get_current_char_as_string(lexer_T* lexer)
{
	char* str = calloc(2, sizeof(char));
	str[0] = lexer->c;
	str[1] = NONE;
	return str;
}
