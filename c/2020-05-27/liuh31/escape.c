#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#define MAX_LEN 100

void escape(char *s, char *t);
void descape(char *s, char *t);

int main () {
    char *s = NULL;
    
    char t[MAX_LEN] = {};
    char d[MAX_LEN] = {};

    size_t mem = 1;

    printf("input: ");
    getline(&s, &mem, stdin);
    escape(s, t);
    printf("escape: %s\n", t);
    descape(t, d);
    printf("descape: %s\n", d);
    return EXIT_SUCCESS;
}

void escape(char s[], char t[]) {
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
            case '\n':
                t[j] = '\\';
                j++;
                t[j] = 'n';
                break;
            case '\t':
                t[j] = '\\';
                j++;
                t[j] = 't';
                break;
            default:
                t[j] = s[i];
                break;
        }
        i++;
        j++;
    }
    t[j] = '\0';
}

void descape(char s[], char t[]) {
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {
        if (s[i] == '\\') {
            i++;
            switch (s[i]) {
                case 'n':
                    t[j] = '\n';
                    break;
                case 't':
                    t[j] = '\t';
                    break;
            }
        } else {
            t[j] = s[i];
        }
        i++;
        j++;
    }
    t[j] = '\0';
}