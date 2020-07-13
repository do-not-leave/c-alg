#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *newNode(int a)
{
	struct node *p;

	p = malloc(sizeof(struct node));
    p->data = a;
    p->next = NULL;
    return p;
}

struct node *pushNode(struct node *item, struct node *n)
{
	if (item == NULL) {
		item->data = n->data;
		item->next = NULL;
		return item;
	}

	struct node *p1;
	p1 = item;
	printf("%d\n", item);
	while(p1->next != NULL)
	{
		p1 = p1->next;
	}
	p1->next = n;

	return p1;
}

struct node *ifAcross(struct node *head1, struct node *head2)
{
	struct node *s1, *s2;
	s1 = head1;
	while(s1->next != NULL) {
		// printf("link1:\n %d\n", s1->next);
		s2 = head2;
		while(s2 != NULL) {
			// printf("%d \t", s2->next);
			if (s1->next == s2->next) {
				return s2->next;
			}
			s2 = s2->next;
		}
		// printf("\n");
		
		s1 = s1->next;
	}
	return s1->next;
}

void showNode(struct node *list)
{
	struct node *p1;
	p1 = list;
	while(p1 != NULL)
	{
		printf("value: %d, next: %d\n", p1->data, p1->next);
		p1 = p1->next;
	}
}

int main(void)
{
	struct node *p1, *p2, *p3, *p4, *l1, *l2, *t;

	l1 = newNode(1);
	l2 = newNode(11);

	p1 = newNode(10);
	p2 = newNode(2);
	p3 = newNode(3);
	p4 = newNode(4);

	pushNode(l1, p1);
	pushNode(l1, p2);
	pushNode(l1, p3);

	pushNode(l2, p3);

	printf("链表1\n");
	showNode(l1);
	printf("链表2\n");
	showNode(l2);

	t = ifAcross(l1, l2);
	
	printf("\n");
	printf("是否相交:%d\n", t);

	return 0;
}