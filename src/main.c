#include <stdio.h>

#include "include/lexer.h"

int main (int argc, char* argv[])
{
	printf("Hello World! What's up? This scrub is learning C and making a programming language at the same time :D What could go wrong?\n");

	set_keywords();

	char* testing_value = "set str name to \"Nicole-Brandon\";";
	printf("Test on [%s]\n", testing_value);
	lexer_T* lexer = init_lexer(testing_value);


	token_T* token = (void*)0;
	while((token = lexer_get_next_token(lexer))->type != TOKEN_END)
	{
		printf("token -> type: %d, value: %s\n", token->type, token->value);
	}

	return 0;
}
