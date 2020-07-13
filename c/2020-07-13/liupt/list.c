#include <stdio.h>
#include <stdlib.h>
 
//链表节点定义 
typedef struct s_node
{
	int data;
	struct s_node* pNext;
}Node;
 
Node* create_list_head();
Node* create_new_node(int node_data);
int add_node_tail(Node* head, Node* new_node); 
void display_list(Node* head);
void free_list(Node* head);
int compare_list(Node* head,Node* head2);

int main(int argc, char *argv[])
{
	//创建链表 
	Node* head = create_list_head();
	if(NULL == head)
	{
		printf("create_list_head failed!\n");
		return -1;
	}

	Node* same = create_list_head();
	int i;
    for(i=1; i<8; i++){
        add_node_tail(same, create_new_node(i));
    }
    printf("same "); 
	display_list(same);

	//填充数据（添加节点） 
	for(i=10; i<18; i++){
		add_node_tail(head, create_new_node(i));
    }
    
    add_node_tail(head, same->pNext);
	//打印原来链表数据 
	printf("befor "); 
	display_list(head);
	

    //创建链表 
	Node* head2 = create_list_head();
	if(NULL == head2)
	{
		printf("create_list_head failed!\n");
		return -1;
	}
	
	//填充数据（添加节点） 
	for(i=8; i<10; i++)
		add_node_tail(head2, create_new_node(i));
 
    add_node_tail(head2, same->pNext);
	//打印原来链表数据 
	printf("befor "); 
	display_list(head2);
	int res = 0;
    res = compare_list(head, head2);
	printf("res %d",res); 

	//释放链表空间 
	// free_list(head);
    // free_list(head2);
	return 0;
}
 
//创建链表 
Node* create_list_head()
{
	Node* head = (Node*)malloc(sizeof(Node));
	if(NULL != head)
	{
		head->data= -1;
		head->pNext= NULL;	
	}
	return head;
} 
 
//创建新节点 
Node* create_new_node(int node_data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if(NULL != new_node)
	{
		new_node->data= node_data;
		new_node->pNext= NULL;	
	}	
	return new_node;
}
 
//尾插法 
int add_node_tail(Node* head, Node* new_node)
{
	if(NULL == head || NULL == new_node)
		return -1;
	Node* tmp = head;
	while( NULL != tmp->pNext )//遍历链表到尾部 
	{
		tmp = tmp->pNext;
	}
	
	tmp->pNext = new_node;
	// new_node->pNext = NULL; 
	return 0;
} 
 
//打印链表数据 
void display_list(Node* head)
{
	if(NULL == head)
		return;
	Node* tmp = head;
	printf("list data:");
	while(NULL !=(tmp=tmp->pNext))
	{
		printf("%d  ", tmp->data);
	}
	printf("\n");
}
 
//释放链表 
void free_list(Node* head)
{
	if(NULL == head) 
		return;
	Node* p = head;
	while((p = p->pNext) != NULL )
	{
		head->pNext = p->pNext;
		//printf("free:%d\n", p->data);
		free(p);
		p = head;
	}
	free(head);
} 
 
int compare_list(Node* head,Node* head2)
{
	if(NULL == head || NULL == head2)
		return 0;
	Node* tmp = head;
    Node* tmp2 = head2;
	printf("list data:");
	while( tmp->pNext!=NULL  )
	{
        tmp = tmp->pNext;
		printf("%d - %d\n", tmp,tmp->data);
	}
    while( tmp2->pNext!=NULL  )
	{
        tmp2 = tmp2->pNext;
		printf("%d - %d\n", tmp2,tmp2->data);
	}
	printf("\n");
    if(tmp == tmp2){
        return 1;
    }
    return 0;
}