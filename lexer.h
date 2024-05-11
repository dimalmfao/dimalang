#ifndef LEXER_H
#define LEXER_H

typedef enum {
    IDENTIFIER,
    NUM,
    PLUS,
    MINUS,
    SLASH,
    LPAREN,
    RPAREN,
    ASTERISK,
    SEMICOLON,
    COMMA,
    PERIOD,
    EQUALS,
    ASSIGNMENT,
    GT,
    LT,
    LEQ,
    GEQ,
    NEG,
    SPACE,
    QUOTED_STR,
    IF,
    WHILE,
    LOOP,
    DUP,
    SWAP,
    OVER,
    DROP,
    PRINT,
    PUTS,
} token_type;

typedef struct {
    token_type type;
    char *value;
} token;

void tokenizer(char *content);

#endif
