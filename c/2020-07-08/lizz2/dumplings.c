/* 包含的头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/* 定义一个表示链表的结构体指针 */
struct list {
	int id;				/* 标识这个元素方便查找 */
	char data[20];		/* 链表中包含的元素 */
	struct list *next;	/* 指向下一个链表的指针 */
};
 
/* 定义一个链表头部 */
static struct list *list_head = NULL;
 
/* 为了保证每一个链表元素的id不同，特意把id定义成一个全局静态变量 */
static int list_id = 0;
 
/**	将指定元素插入到链表尾部
  * 	head	: 表示要插入元素的链表的头部的地址
  *	list    : 表示要插入到链表中的元素
  */
static void list_add(struct list **head, struct list *list)
{
	struct list *temp;
 
	/* 判断链表是否为空 */
	if(NULL == *head)
	{
		/* 为空 */
		*head = list;
		(*head)->next = NULL;
	}
	else
	{
		/* 不为空 */
		temp = *head;
		while(temp)
		{
			if(NULL == temp->next)
			{
				temp->next = list;
				list->next = NULL;
			}
			temp = temp->next;
		}
	}
}
 
/** 遍历一个链表，打印链表中每个元素所包含的数据
  * head : 表示要遍历的链表的头部的指针
  */
static void list_print(struct list **head)
{	
	struct list *temp;
 
	temp = *head;
 
	printf("list information :\n");
	while(temp)
	{
		printf("\tlist %d : %s\n", temp->id, temp->data);
		temp = temp->next;
	}
}
 
/**	将指定元素从链表尾部删除
  * 	head	: 表示要删除元素的链表的头部的地址
  *	id      : 表示要删除元素的标识
  *	返回值  : 0-成功，-1-失败
  */
static int list_del(struct list **head, int id)
{
	struct list *temp, *p;
	temp = *head;
 
	if(NULL == temp)
	{
		/* 链表为空 */
		printf("链表为空!\n");
		return -1;
	}
	else
	{
		/* 判断匹配的元素是否为链表头部的元素 */
		if(id == temp->id)		/* 是链表头部 */
		{
			*head = temp->next;
			return 0;
		}
		else					/* 不是链表头部 */
		{
			while(temp->next)
			{
				p = temp;
				temp = temp->next;
 
				if(id == temp->id)
				{
					p->next = temp->next;
					return 0;
				}
			}	
			return -1;
		}
	}
 
	return -1;
}
 
/**	将指定id的元素所定义的内容进行修改
  * 	head	: 表示要改变元素的链表的头部的地址
  *	id      : 表示要改变元素的标识
  *	content : 表示要改变的内容
  *	返回值  : 0-成功，-1-失败
  */
static int list_chg(struct list **head, int id, char *content)
{
	struct list *temp;
 
	temp = *head;	/* 将链表的头部赋值给临时聊表变量 */
 
	while(temp)		/* 对链表进行轮询 */
	{
		if(id == temp->id)
		{
			memset(temp->data, 0, sizeof(temp->data));
			sprintf(temp->data, "%s", content);
			temp->data[strlen(content)] = '\0';
			return 0;
		}
		temp = temp->next;
	}
	return -1;
}
 
/**	将指定id的元素所定义的内容进行查找
  * 	head	: 表示要查询元素的链表的头部的地址
  *	id      : 表示要查询元素的标识
  *	返回值  : 0-成功，-1-失败
  */
static int list_query(struct list **head, int id)
{
	struct list *temp;
 
	temp = *head;	/* 将链表的头部赋值给临时聊表变量 */
 
	while(temp)		/* 对链表进行轮询 */
	{
		if(id == temp->id)
		{
			printf("list %d : %s\n", temp->id, temp->data);
			return 0;
		}
		temp = temp->next;
	}
 
	/* 没有找到元素 */
	printf("not finding!\n");
	
	return -1;
}
 
 
/* 主函数，程序的入口 */
int main(int argc, char *argv[])
{
	int i = 0;
	struct list *lists = NULL;
 
	struct list temp_list;
 
	/* 分配10个元素 */
	lists = malloc(sizeof(struct list) * 10);
	if(NULL == lists)
	{
		printf("malloc error!\n");
		return -1;
	}
 
	/* 将分配的10个元素依次填充数据并加入到链表当中 */
	for(i = 0; i < 10; i++)
	{
		lists[i].id = list_id++;
		sprintf(lists[i].data, "TECH-PRO - %d", i);
 
		list_add(&list_head, &lists[i]);
	}
 
	/* 填充这个结构体并加入链表当中 */
	temp_list.id = list_id++;
	sprintf(temp_list.data, "temp_list");
	list_add(&list_head, &temp_list);
 
	/* 删除链表中开始位置、中间位置、尾部的元素 */
	list_del(&list_head, 0);
	list_del(&list_head, 5);
	list_del(&list_head, 10);
 
	/* 改变id为4的元素所对应的值为 "change!!!" */
	list_chg(&list_head, 4, "change!!!");
 
	/* 查询链表中id为4的元素结点的内容 */
	list_query(&list_head, 4);
 
	return 0;
}
