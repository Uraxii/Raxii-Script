#ifndef KEYWORD_H
#define KEYWORD_H

typedef struct KEYWORD_S
{
	enum
	{
		KW_SET,
		KW_TO,
		KW_STR,
		KW_INT,
	};

	unsigned int type;
	char* value;
} keyword_T;

keyword_T* KEYWORDS[4];

keyword_T* init_keyword(int type_id, char* contents);
#endif
