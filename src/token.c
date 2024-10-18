#include "include/token.h"
#include <stdlib.h>

token_T* init_token(int type, char* contents)
{
	token_T* token_T = calloc(1, sizeof(struct TOKEN_S));
	token_T->type = type;
	token_T->value = contents;
	return token_T;
}
