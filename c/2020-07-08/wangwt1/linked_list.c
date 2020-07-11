#include <stdio.h>


struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	struct ListNode *pre = head;
	struct ListNode *cur = head->next;
	struct ListNode *tmp = head->next->next;

	while (cur) {
		tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	head->next = NULL;

	return pre;
};

int main()
{

}