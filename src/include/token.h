#ifndef TOKEN_H
#define TOKEN_H

typedef struct TOKEN_S
{
	enum
	{
		TOKEN_UNKNOWN,
		TOKEN_RPARENTHESES,
		TOKEN_KW_SET,
		TOKEN_KW_TO,
		TOKEN_KW_UINT8,
		TOKEN_KW_FUNCTION,
		TOKEN_KW_STRING,
		TOKEN_ID,
		TOKEN_STRING,
		TOKEN_SEMICOLON,
		TOKEN_LPARENTESES,
		TOKEN_SYMBOL,
		TOKEN_END,
	} type;
	
	char* value;
} token_T;

token_T* init_token(int type, char* contents);

void forward(token_T* lexer);

void ignore_whitespace(token_T* lexer);

#endif
