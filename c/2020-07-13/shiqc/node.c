#include <stdio.h>
#include <stdlib.h>
struct LinkNode *NewLinkNode();
void PrintNode(struct LinkNode *node);

// 定义链表
struct LinkNode {
    int val ;
    struct LinkNode *next;
};

// 创建链表
void createNode(struct LinkNode *node,int n){
    struct LinkNode *cur;
    cur = node;
    for (int i = 1; i <= n; i++)
    {
        cur->val = i;
        cur->next = NewLinkNode();// 创建新的节点
        cur = cur->next;
    }
}


int main() {
    struct LinkNode node;
    createNode(&node,8);
    PrintNode(&node);
    return EXIT_SUCCESS;
}

//构造链表节点
struct LinkNode *NewLinkNode() {
    struct LinkNode *p;
    p = (struct LinkNode*)malloc(sizeof(struct LinkNode));
    p->val = 10000;
    p->next = NULL;
    return p;
}

// 打印链表
void PrintNode(struct LinkNode *node) {
    struct LinkNode *start;
    start = node;
    while (start->next !=NULL) {
        printf("%d, ", start->val);
        start = start->next;
    }
}