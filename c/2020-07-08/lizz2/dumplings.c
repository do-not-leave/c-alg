/* ������ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/* ����һ����ʾ����Ľṹ��ָ�� */
struct list {
	int id;				/* ��ʶ���Ԫ�ط������ */
	char data[20];		/* �����а�����Ԫ�� */
	struct list *next;	/* ָ����һ�������ָ�� */
};
 
/* ����һ������ͷ�� */
static struct list *list_head = NULL;
 
/* Ϊ�˱�֤ÿһ������Ԫ�ص�id��ͬ�������id�����һ��ȫ�־�̬���� */
static int list_id = 0;
 
/**	��ָ��Ԫ�ز��뵽����β��
  * 	head	: ��ʾҪ����Ԫ�ص������ͷ���ĵ�ַ
  *	list    : ��ʾҪ���뵽�����е�Ԫ��
  */
static void list_add(struct list **head, struct list *list)
{
	struct list *temp;
 
	/* �ж������Ƿ�Ϊ�� */
	if(NULL == *head)
	{
		/* Ϊ�� */
		*head = list;
		(*head)->next = NULL;
	}
	else
	{
		/* ��Ϊ�� */
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
 
/** ����һ��������ӡ������ÿ��Ԫ��������������
  * head : ��ʾҪ�����������ͷ����ָ��
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
 
/**	��ָ��Ԫ�ش�����β��ɾ��
  * 	head	: ��ʾҪɾ��Ԫ�ص������ͷ���ĵ�ַ
  *	id      : ��ʾҪɾ��Ԫ�صı�ʶ
  *	����ֵ  : 0-�ɹ���-1-ʧ��
  */
static int list_del(struct list **head, int id)
{
	struct list *temp, *p;
	temp = *head;
 
	if(NULL == temp)
	{
		/* ����Ϊ�� */
		printf("����Ϊ��!\n");
		return -1;
	}
	else
	{
		/* �ж�ƥ���Ԫ���Ƿ�Ϊ����ͷ����Ԫ�� */
		if(id == temp->id)		/* ������ͷ�� */
		{
			*head = temp->next;
			return 0;
		}
		else					/* ��������ͷ�� */
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
 
/**	��ָ��id��Ԫ������������ݽ����޸�
  * 	head	: ��ʾҪ�ı�Ԫ�ص������ͷ���ĵ�ַ
  *	id      : ��ʾҪ�ı�Ԫ�صı�ʶ
  *	content : ��ʾҪ�ı������
  *	����ֵ  : 0-�ɹ���-1-ʧ��
  */
static int list_chg(struct list **head, int id, char *content)
{
	struct list *temp;
 
	temp = *head;	/* �������ͷ����ֵ����ʱ�ı���� */
 
	while(temp)		/* �����������ѯ */
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
 
/**	��ָ��id��Ԫ������������ݽ��в���
  * 	head	: ��ʾҪ��ѯԪ�ص������ͷ���ĵ�ַ
  *	id      : ��ʾҪ��ѯԪ�صı�ʶ
  *	����ֵ  : 0-�ɹ���-1-ʧ��
  */
static int list_query(struct list **head, int id)
{
	struct list *temp;
 
	temp = *head;	/* �������ͷ����ֵ����ʱ�ı���� */
 
	while(temp)		/* �����������ѯ */
	{
		if(id == temp->id)
		{
			printf("list %d : %s\n", temp->id, temp->data);
			return 0;
		}
		temp = temp->next;
	}
 
	/* û���ҵ�Ԫ�� */
	printf("not finding!\n");
	
	return -1;
}
 
 
/* ���������������� */
int main(int argc, char *argv[])
{
	int i = 0;
	struct list *lists = NULL;
 
	struct list temp_list;
 
	/* ����10��Ԫ�� */
	lists = malloc(sizeof(struct list) * 10);
	if(NULL == lists)
	{
		printf("malloc error!\n");
		return -1;
	}
 
	/* �������10��Ԫ������������ݲ����뵽������ */
	for(i = 0; i < 10; i++)
	{
		lists[i].id = list_id++;
		sprintf(lists[i].data, "TECH-PRO - %d", i);
 
		list_add(&list_head, &lists[i]);
	}
 
	/* �������ṹ�岢���������� */
	temp_list.id = list_id++;
	sprintf(temp_list.data, "temp_list");
	list_add(&list_head, &temp_list);
 
	/* ɾ�������п�ʼλ�á��м�λ�á�β����Ԫ�� */
	list_del(&list_head, 0);
	list_del(&list_head, 5);
	list_del(&list_head, 10);
 
	/* �ı�idΪ4��Ԫ������Ӧ��ֵΪ "change!!!" */
	list_chg(&list_head, 4, "change!!!");
 
	/* ��ѯ������idΪ4��Ԫ�ؽ������� */
	list_query(&list_head, 4);
 
	return 0;
}
