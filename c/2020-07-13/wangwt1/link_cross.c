#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}ElemSN;

//逆向建链
ElemSN *createLink(int a[], int n)
{
	ElemSN *p, *h = NULL;
	for (int i=n-1;i>-1; i--)
	{
		p = (ElemSN *)malloc(sizeof(ElemSN));
		p->data = a[i];
		p->next = h;
		h = p;
	}
	return h;
}


ElemSN *across(ElemSN *head1, ElemSN *head2)
{
	ElemSN *p1, *p2;
	
	p2=head2;
	while (p2 != NULL)
	{
		printf("p2 %d\n", p2);

		for (p1=head1; p1&&p1-p2; p1=p1->next)
		{
			printf("p1 %d\n", p1);
			if (!p1)
				p2 = p2->next;
			else
				break;
		}
	}

	return p2;
}

ElemSN *ifAcross(ElemSN *head1, ElemSN *head2)
{
	ElemSN *start, *s2;
	start = head1;
	while(start->next != NULL) {
		printf("link1:\n %d\n", start->next);
		s2 = head2;
		while(s2->next != NULL) {
			printf("%d \t", s2->next);
			if (start == s2) {
				return start;
			}
			s2 = s2->next;
		}
		printf("\n");
		
		start = start->next;
	}

	return start;
}

int main(void)
{
	int a[6] = {3,1,5,6,7,2};
	int b[8] = {1,5,3,6,7,2,8,9};

	ElemSN *head1, *head2, *PI;
	head1 = createLink(a, 6);
	head2 = createLink(b, 8);
	printf("h1 %d, h2 %d\n", head1, head2);
	// PI = ifAcross(head2, head1);
	PI = across(head1, head2);
	printf("%d\n", PI->data);

	return 0;
}