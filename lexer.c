#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lexer.h"

static bool isSeparator(char ch) {
    return ch == ' ';
}

void tokenizer(char *content) {
    size_t length = strlen(content); // Store the length of the content to avoid recalculating it in the loop

    for (size_t i = 0; i < length; ++i) {
        if (isSeparator(content[i])) {
            printf("Is space\n");
        } else {
            printf("Is not space\n");
        }
    }
}
