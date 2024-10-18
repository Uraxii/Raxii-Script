#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ast.h"
#include "token.h"


typedef struct PARSER_S
{
	lexer_T* lexer;
	token_T* current_token;
} parser_T;

parser_T* init_parser(lexer_T* lexer);

void parser_consume(parser_T* parser, int token_type);

ast_T* parser_parse(parser_T* parser);

ast_T* parser_parse_statement(parser_T* parser);

ast_T* parser_parse_statements(parser_T* parser);

ast_T* parser_parse_keyword_set(parser_T* parser);

ast_T* parser_parse_expression(parser_T* parser);

ast_T* parser_parse_factor(parser_T* parser);

ast_T* parser_parse_term(parser_T* parser);

ast_T* parser_parse_function_call(parser_T* parser);

ast_T* parser_parse_variable(parser_T* parser);

ast_T* parser_parse_string(parser_T* parser);

#endif
