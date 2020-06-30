#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
    int lineNo = 0, start = 0;
    char *lines[MAXLINE];
    char *p;
    char *stop = "stop";

    char *tailLine;
    int tailLineNum = 0;

    char *line = NULL;

    size_t mem_len = 0;
    ssize_t line_len;
    
    if (argc != 3) {
        return EXIT_FAILURE;
    }

    tailLine = argv[2];
    
    tailLineNum = atoi(tailLine);

    while ((line_len = getline(&line, &mem_len, stdin)) != -1) {
        if (strncmp(line, stop, 4) == 0) {
            printf("\n");
            break;
        }
        p = malloc(MAXLINE);
        strcpy(p, line);
        lines[lineNo++] = p;
    }

    if (tailLineNum >= lineNo) {
      start = 0;
    } else {
      start = lineNo - tailLineNum;
    }
    for (int i = start; i < lineNo; i++) {
        printf("%s", lines[i]);
    }
}