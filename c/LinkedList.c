#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode * initLL () {
	struct ListNode * ln = malloc(sizeof(struct ListNode));
	ln->val = 0;
	ln->next = NULL;
	return ln;
}

struct ListNode * appendLLpre (struct ListNode * ln, int val) {
	struct ListNode * lnNew = malloc(sizeof(struct ListNode));
	ln->next = lnNew;
	lnNew->val = val;
	lnNew->next = NULL;
	return lnNew;
}

struct ListNode * appendLL (struct ListNode * ln, int val) {
	struct ListNode * lnNew = malloc(sizeof(struct ListNode));
	lnNew->val = val;
	lnNew->next = ln;
	return lnNew;
}

void print_r(struct ListNode * ln)
{
	struct ListNode * tmpNode;
	for(tmpNode = ln->next; tmpNode->next != NULL; tmpNode = tmpNode->next)
	{
		printf("%d ", tmpNode->val);
	}
	printf("%d\n", tmpNode->val);
}

void print_r2(struct ListNode * ln)
{
	struct ListNode * tmpNode;
	for(tmpNode = ln; tmpNode->next != NULL; tmpNode = tmpNode->next)
	{
		printf("%d ", tmpNode->val);
	}
	printf("%d\n", tmpNode->val);
}

int main()
{
	struct ListNode * llHeadA = initLL();
	struct ListNode * llPtrA = appendLLpre(llHeadA, 3);
	llPtrA = appendLLpre(llPtrA, 6);
	llPtrA = appendLLpre(llPtrA, 90);
	print_r(llHeadA);

	struct ListNode * llPtrB = initLL();
	llPtrB = appendLL(llPtrB, 3);
	llPtrB = appendLL(llPtrB, 6);
	llPtrB = appendLL(llPtrB, 90);
	print_r2(llPtrB);

	return 0;
}
