#include <stdio.h>
#include <stdlib.h>
struct LinkNode *NewLinkNode();
void PrintNode(struct LinkNode *node,char *str);
struct LinkNode *findmeeta(struct LinkNode * node1,struct LinkNode *node2);

// 定义链表
struct LinkNode {
    int val ;
    struct LinkNode *next;
};

// 创建链表
struct LinkNode *createNode(struct LinkNode *node,int n,int start){
	struct LinkNode *reNode;
    struct LinkNode *cur;
    cur = node;
    for (int i = 1; i <= n; i++)
    {
        cur->val = i;
        cur->next = NewLinkNode();// 创建新的节点
        cur = cur->next;
        if(start > 0 && i==start){
        	reNode = cur;
        }
    }
    return reNode;
}


int main() {
    struct LinkNode node1;
    struct LinkNode node2;
    struct LinkNode *mid;
    struct LinkNode *end;
    struct LinkNode *meeta;
    mid = createNode(&node1,8,4);
    end = createNode(&node2,5,5);
    end->next = mid;
    PrintNode(&node1,"node1");
    PrintNode(&node2,"node2");
    meeta = findmeeta(&node1,&node2);
    if(meeta){
    	printf("在节点值为%d相遇\n", meeta->val);
    }
    return EXIT_SUCCESS;
}

struct LinkNode *findmeeta(struct LinkNode * node1,struct LinkNode *node2){
	int n1,n2 = 0;
	struct LinkNode *tmp1,*tmp2;
	tmp1 = node1;
	tmp2 = node2;

	while(tmp1->next !=NULL){
		n1++;
		tmp1 = tmp1->next;
	}

	while(tmp2->next !=NULL){
		n2++;
		tmp2 = tmp2->next;
	}
	if(tmp1 != tmp2){
		return NULL;
	}

	if(n2>n1){
		for(int i=0;i<n2-n1;i++){
			node2 = node2->next;
		}
	}else{
		for(int i=0;i<n1-n2;i++){
			node1 = node1->next;
		}
	}
	while(node1 != node2){
		node1 = node1->next;
		node2 = node2->next;
	}
	return node1;
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
void PrintNode(struct LinkNode *node,char *str) {
    struct LinkNode *start;
    start = node;
    printf("%s:", str);
    while (start->next !=NULL) {
        printf("%d, ", start->val);
        start = start->next;
    }
    printf("\n");
}