#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

typedef struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
} tnode;


struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
void treesort(tnode *p, tnode *s[]);

int main () {
    struct tnode *root;
    int i = 0;

    char *word[7] = {"hello", "i", "good", "morning", "i", "good", "i"};
    root = NULL;

    for (i = 0; i < 7; i++) {
        root = addtree(root, word[i]);
    }
    
    treeprint(root);

    tnode *s[MAXWORD];
    for (i = 0; i < MAXWORD; i++) {
        s[i] = NULL;
    }

    treesort(root, s);
    printf("%s\n", "--------------------");
    i = 0;
    for (i = 0; s[i] != NULL; i++) {
        printf("%4d %s\n", s[i]->count, s[i]->word);
    }

    return EXIT_SUCCESS;
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    } else if (cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

void treesort(tnode *p, tnode *s[]) {
    int i = 0, l = 0;
    if (p != NULL) {
        treesort(p->left, s);

        while (s[l] != NULL) {
            l++;
        }
        for (i = l - 1; i >= 0; i--) {
            if (s[i]->count < p->count) {
                s[i+1] = s[i];
            } else {
                break;
            }
        }
        s[i+1] = p;
        treesort(p->right, s);
    }
}