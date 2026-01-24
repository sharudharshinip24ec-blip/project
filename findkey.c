#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[32][10] = {
    "auto","break","case","char","const","continue","default",
    "do","double","else","enum","extern","float","for","goto",
    "if","int","long","register","return","short","signed",
    "sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"
};

int isKeyword(char buffer[]) {
    int i;
    for (i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], buffer) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[50];
    int i = 0;

    fp = fopen("input.c", "r");

    if (fp == NULL) {
        printf("Error while opening the file\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        // Operator check
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>') {
            printf("Operator : %c\n", ch);
        }

        // Identifier / Keyword check
        if (isalnum(ch)) {
            buffer[i++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (i != 0)) {
            buffer[i] = '\0';
            i = 0;

            if (isKeyword(buffer))
                printf("Keyword : %s\n", buffer);
            else
                printf("Identifier : %s\n", buffer);
        }
    }

    fclose(fp);
    return 0;
}