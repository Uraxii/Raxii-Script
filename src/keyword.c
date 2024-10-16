#include "include/keyword.h"
#include <stdlib.h>


int NEWLINE = 10;
char NONE = '\0';
char WHITESPACE = ' ';
keyword_T* KEYWORDS[4];


keyword_T* init_keyword(int type, char* contents)
{
	keyword_T* keyword_T = calloc(1, sizeof(struct KEYWORD_S));
	keyword_T->type = type;
	keyword_T->value = contents;
	return keyword_T;
}

void set_keywords()
{
	KEYWORDS[0] = init_keyword(KW_SET, "set");
	KEYWORDS[1] = init_keyword(KW_TO, "to");
	KEYWORDS[2] = init_keyword(KW_STR, "str");
	KEYWORDS[3] = init_keyword(KW_INT, "int");
}

