#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *nextnode;
} LNODE;

LNODE * create_head();
LNODE * add_node(LNODE * n, int v);
void display_list(LNODE * p);

int main()
{
    LNODE *p, *h;
    h = p = create_head();
    for (int i=1;i<10;i++)
    {
        p = add_node(p, 2*i);
    }
    display_list(h);
}

LNODE * create_head() {
    LNODE *p = malloc(sizeof(LNODE));
    p->data = 0;
    p->nextnode = NULL;
    return p;
}
LNODE * add_node(LNODE * n, int v)
{
    LNODE *p = malloc(sizeof(LNODE));
    p->data = v;
    p->nextnode = NULL;
    n->nextnode = p;
    n = n->nextnode;
    return n;
}
void display_list(LNODE * p)
{
    if (p->nextnode != NULL) {
        printf("%d ",p->data);
        display_list(p->nextnode);
    } else {
        printf("%d end",p->data);
    }
}