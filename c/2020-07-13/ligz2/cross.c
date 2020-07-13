#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *nextnode;
} LNODE;

LNODE * create_head();
LNODE * add_node(LNODE * n, int v);
void display_list(LNODE * p);
LNODE * create_list(int data[],int len);
int has_cross(LNODE *a, LNODE *b);
int main()
{
    LNODE *p, *q, *h;
    int d;
    int a[]= {1,4,8,7,2}, b[]= {2,8,10,3,5};
    p = create_list(a,5);
    display_list(p->nextnode);

    q = create_list(b,5);
    display_list(q->nextnode);
    d = has_cross(p->nextnode, q->nextnode);
    printf("cross %d",d);




    // h = p = create_head();
    // for (int i=1;i<10;i++)
    // {
    //     p = add_node(p, 2*i);
    // }
    // display_list(h->nextnode);
}

int has_cross(LNODE *a, LNODE *b)
{
    LNODE *ta, *tc;
    tc = b;
    int flag = 0;
    while(1)
    {
        int avalue = a->data;
        while(1) {
            int bvalue = b->data;
            printf("a:b %d:%d\n",avalue,bvalue);
            if (bvalue == avalue) {
                return 1;
            } else {
                if (b->nextnode == NULL) {
                    break;
                } else {
                    b = b->nextnode;
                }
            }
        }
        if (a->nextnode == NULL)
        {
            break;
        } else {
            a = a->nextnode;
            b = tc;
        }

    }
    return 0;

}

LNODE * create_list(int data[], int len) {
    LNODE *p, *h;
    h = p = create_head();
    for (int i=0;i<len;i++)
    {
        p = add_node(p, data[i]);
    }
    return h;
}

LNODE * create_head() {
    LNODE *p = malloc(sizeof(LNODE));
    // p->data = 0;
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