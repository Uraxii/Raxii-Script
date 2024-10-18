#include "include/ast.h"


ast_T* init_ast(int type)
{
	ast_T* ast = calloc(1, sizeof(struct AST_S));

	ast->type = type;

	/* AST VARIABLE DEF */
	ast->ast_variable_definiton_name = (void*) 0;
	ast->ast_variable_definition_value = (void*) 0;

	/* Variable */
	ast->variable_name = (void*) 0;

	/* Function */
	ast->function_call_name = (void*) 0;
	ast->function_call_arguments = (void*) 0;
	ast->number_of_parameters_in_function_call = 0;

	/* String */
	ast->string_value = (void*) 0;

	/* AST node list */
	ast->nodes = (void*) 0;
	ast->number_of_nodes = 0;

	return ast;
}
