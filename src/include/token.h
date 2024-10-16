#ifndef TOKEN_H
#define TOKEN_H

typedef struct TOKEN_S
{
	enum
	{
		TOKEN_UNKNOWN,
		TOKEN_SET,
		TOKEN_TO,
		TOKEN_STRING,
		TOKEN_UINT8,
		TOKEN_FUNCTION,
		TOKEN_SEMICOLON,
		TOKEN_LPARENTESES,
		TOKEN_RPARENTHESES,
	};

	char* value;
} token_T;

token_T* init_token(int type, char* contents);

void forward(token_T* lexer);

void ignore_whitespace(token_T* lexer);

#endif
