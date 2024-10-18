#ifndef AST_H
#define AST_H

#include <stdlib.h>

typedef struct AST_S
{
	enum{
		AST_SET_VARIABLE,
		AST_VARIABLE_REFERENCE,
		AST_FUNCTION_CALL,
		AST_STRING,
		AST_NODE_ARRAY,
	} type;

	/* AST VARIABLE DEF */
	char* ast_variable_definiton_name;
	struct AST_S* ast_variable_definition_value;

	/* Variable */
	char* variable_name;

	/* Function */
	char* function_call_name;
	struct AST_S** function_call_arguments;
	size_t number_of_parameters_in_function_call;

	/* String */
	char* string_value;

	/* AST node list */
	struct AST_S** nodes;
	size_t number_of_nodes;
} ast_T;

ast_T * init_ast(int type);


#endif
