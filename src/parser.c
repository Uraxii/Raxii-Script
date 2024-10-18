#include <stdio.h>
#include <stdlib.h>


#include "include/parser.h"
#include "include/ast.h"
#include "include/lexer.h"
#include "include/token.h"


parser_T* init_parser(lexer_T* lexer)
{
	parser_T* parser = calloc(1, sizeof(struct PARSER_S));
	parser->lexer = lexer;
	parser->current_token = lexer_get_next_token(lexer);

	return parser;
}

void parser_consume(parser_T* parser, int token_type)
{
	if(parser->current_token->type != token_type)
	{
		printf(
			"Unexpected token [%s] with type [%d]!",
			parser->current_token->value,
			parser->current_token->type
		);
		exit(1);
	}

	parser->current_token = lexer_get_next_token(parser->lexer);
}

ast_T* parser_parse(parser_T* parser)
{

}

ast_T* parser_parse_statement(parser_T* parser)
{
	switch (parser->current_token->type)
	{
		case TOKEN_ID: return parser_parse_keyword_set(parser);
	}
}

ast_T* parser_parse_statements(parser_T* parser)
{
	ast_T* node_array = init_ast(AST_NODE_ARRAY);
	node_array->nodes = calloc(1, sizeof(struct AST_S*));

	ast_T* ast_statement = parser_parse_statement(parser);
	node_array->nodes[0] = ast_statement;

	while(parser->current_token->type == TOKEN_SEMICOLON)
	{
		parser_consume(parser, TOKEN_SEMICOLON);

		ast_T* ast_statement = parser_parse_statement(parser);
		node_array->number_of_nodes += 1;
		node_array->nodes = realloc(
			node_array->nodes,
			node_array->number_of_nodes * sizeof(struct AST_S*)
		);
		node_array->nodes[node_array->number_of_nodes - 1] = ast_statement;
	}

	return node_array;
}

ast_T* parser_parse_expression(parser_T* parser)
{

}

ast_T* parser_parse_factor(parser_T* parser)
{

}

ast_T* parser_parse_term(parser_T* parser)
{

}

ast_T* parser_parse_function_call(parser_T* parser)
{

}

ast_T* parser_parse_keyword_set(parser_T* parser)
{
	parser_consume(parser, TOKEN_ID); // variable name
	char* ast_variable_name = parser->current_token->value;
	parser_consume(parser, TOKEN_ID);
	ast_T* ast_variable_value = parser_parse_expression(parser);

	ast_T* set_variable = init_ast(AST_SET_VARIABLE);
	set_variable->ast_variable_definiton_name = ast_variable_name;
	set_variable->ast_variable_definition_value = ast_variable_value;

	return set_variable;
}

ast_T* parser_parse_variable(parser_T* parser)
{

}

ast_T* parser_parse_string(parser_T* parser)
{

}
