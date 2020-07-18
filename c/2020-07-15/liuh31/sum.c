#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct LinkNode {
    int x;
    int y;
    int sum;
};

struct Hash {
    int cap;
    struct LinkNode *l;
};

struct Hash *NewHash(int cap) {
    struct Hash *p;
    struct LinkNode *l;

    p = malloc(sizeof(struct Hash));

    l = malloc(cap * sizeof(struct LinkNode));
    p->cap = cap;
    p->l = l;

    return p;
}

int main() {
    int len = 10;
    int list[len];
    struct Hash *hash;
    
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);
    srand(p->tm_sec);
    for (int i = 0; i < len; i++) {
        list[i] = rand() % 100;
    }

    hash = NewHash(len);

    

    return EXIT_SUCCESS;
}