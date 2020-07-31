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
int circle_list(Node* head);

int main(int argc, char *argv[])
{
	//创建链表 
	Node* head = create_list_head();
	if(NULL == head)
	{
		printf("create_list_head failed!\n");
		return -1;
	}

    //生成环
	Node* same = create_list_head();
	int i;
    for(i=10; i<18; i++){
        add_node_tail(same, create_new_node(i));
    }
    add_node_tail(same, same->pNext);


    printf("same "); 
	display_list(same);

	//填充数据（添加节点） 
	for(i=1; i<10; i++){
		add_node_tail(head, create_new_node(i));
    }
    
    add_node_tail(head, same->pNext);
	//打印原来链表数据 
	printf("befor "); 
	display_list(head);
	

	int res = 0;
	res = circle_list(head);
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
	int maxCount = 0;
	if(NULL == head)
		return;
	Node* tmp = head;
	while(NULL !=(tmp=tmp->pNext) && maxCount++<100)
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
 
int circle_list(Node* head)
{
	if(NULL == head)
		return 0;
	Node* tmp = head;
	Node* tmp2 = head;
	int res = 0;
	printf("list data:");
	while( tmp->pNext!=NULL && tmp2->pNext !=NULL && tmp2->pNext->pNext!=NULL  )
	{

        tmp = tmp->pNext;
		tmp2 = tmp2->pNext->pNext;
		printf("%d - %d\n", tmp->data,tmp2->data);
		if(tmp2 == tmp){
			res = 1;
			break;
		}
	}
	tmp = head;
	while( tmp->pNext!=NULL && tmp2->pNext !=NULL  )
	{

        tmp = tmp->pNext;
		tmp2 = tmp2->pNext;
		printf("%d - %d\n", tmp->data,tmp2->data);
		if(tmp2 == tmp){
			printf("入环节点 %d - %d\n", tmp->data,tmp2->data);
			break;
		}
	}
	return res;
}