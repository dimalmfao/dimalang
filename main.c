#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "lexer.h"

void getFileName(char *file, char **args); 
bool checkFileFormat(char *file_name);
size_t getFileSize(FILE* file);
void getString(char *str_to, FILE* content_from);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Invalid file name. Use '.dima'.\n"); 
        return -1;
    }

    char *file = malloc(sizeof(argv[1]));
    getFileName(file, argv);

    if (!checkFileFormat(file)) {
        printf("Invalid file name. Use '.dima'.\n");
        return -1;
    }

    FILE* content = fopen(file, "r");

    if (content == NULL) {
        printf("An error occurred while reading the file.\n");
        return -1;
    }

    size_t fileSize = getFileSize(content);

    char *contentString = malloc(sizeof(char) * fileSize);

    getString(contentString, content);
    fclose(content);

    printf("%s", contentString);
    return 0;
}

void getFileName(char *file, char **args) {
    for(size_t i = 0; i < strlen(args[1]); ++i) {
        file[i] = args[1][i];
    }
}

bool checkFileFormat(char *file_name) {
    size_t dotIndex = 0;
    for (size_t i = 0; i < strlen(file_name); ++i) {
        if (file_name[i] == '.') {
            dotIndex = i;
        }
    }

    char *buff = malloc(6);
    
    for(size_t j = 0; dotIndex < strlen(file_name); ++dotIndex, ++j) {
        buff[j] = file_name[dotIndex];
    }
    
    if (strcmp(buff, ".dima") == 0) {
        return true;
    }
    return false;
}

size_t getFileSize(FILE* file) {
    size_t size = 0;

    for (size; fgetc(file) != EOF; size++);
    fseek(file, 0, SEEK_SET);
    return size;
}

void getString(char *str_to, FILE* content_from) {
    for (size_t i = 0; !feof(content_from); str_to[i] = fgetc(content_from), ++i);
}
