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
        cur->next = NewLinkNode();
        cur->val = i;
        printf("%d, ", cur->val);
        cur = cur->next;
        printf("%d, ", cur->val);
    }
    
}


int main() {
    struct LinkNode node;
    node.val = -1;
    node.next = NULL;
    createNode(&node,1);
    PrintNode(&node);
    return EXIT_SUCCESS;
}

//构造链表节点
struct LinkNode *NewLinkNode(int n) {
    struct LinkNode r, *p = &r;
    p->val = 1000000;
    p->next = NULL;
    return p;
}

// 打印链表
void PrintNode(struct LinkNode *node) {
    printf("%d, ", node->next->val);
    // struct LinkNode *start;
    // start = node;
    // while (start->next != NULL) {
    //     start = start->next;
    //     printf("%d, ", start->val);
    // }
}