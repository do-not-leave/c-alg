#include <stdio.h>
#include <stdlib.h>
struct LinkNode *NewLinkNode();
void PrintNode(struct LinkNode *node,char *str);
struct LinkNode *findLoopNode(struct LinkNode *node1,struct LinkNode *meet);
struct LinkNode *IsLoop(struct LinkNode *node);
// 定义链表
struct LinkNode {
	int val;
	struct LinkNode *next;
};
//构造链表节点
struct LinkNode *NewLinkNode() {
    struct LinkNode *p;
    p = (struct LinkNode*)malloc(sizeof(struct LinkNode));
    p->val = 10000;
    p->next = NULL;
    return p;
}

// 创建链表
void createNode(struct LinkNode *node,int n,int start){
	struct LinkNode *reNode;
	struct LinkNode *cur;
	cur = node;
	for(int i = 1;i<=n;i++)
	{
		cur->val = i;
        cur->next = NewLinkNode();// 创建新的节点
        cur = cur->next;
        if(start > 0 && i==start){
        	reNode = cur;
        }
		if(i == n){
			cur->next = reNode;
		}
	}
}

int main(){
	struct LinkNode node1;
	struct LinkNode *meeta;
	struct LinkNode *door;
    createNode(&node1,8,4);
	meeta = IsLoop(&node1);
	if(meeta != NULL){
		printf("有环，相遇节点：%d, ", meeta->val);
		door = findLoopNode(&node1,meeta);
		if(door !=NULL){
			printf("入口：%d, ", door->val);
		}
	}

    //PrintNode(&node1,"node1");
}

// 找出环入口点
struct LinkNode *findLoopNode(struct LinkNode *node1,struct LinkNode *meet){
	struct LinkNode *tmp1;
	struct LinkNode *tmp2;
	tmp1 = node1;
	tmp2 = meet;
	for (;tmp1->next != NULL;) {
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		if(tmp1 == tmp2){
			break;
		}
	}
	return tmp1;
}
// 判断是否有环
struct LinkNode *IsLoop(struct LinkNode *node){
	struct LinkNode *fast;
	struct LinkNode *slow;
	fast = node->next;
	slow = node->next;
	for (;fast != NULL && fast->next !=NULL;) {
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow){
			return fast;
		}
	}
	return NULL;
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