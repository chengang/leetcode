#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode * initLL (int val) {
	struct ListNode * ln = malloc(sizeof(struct ListNode));
	ln->val = val;
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
	for(tmpNode = ln; tmpNode != NULL; tmpNode = tmpNode->next)
	{
		printf("%d ", tmpNode->val);
	}
	printf("\n");
}

int lenLL(struct ListNode *head)
{
	int count = 0;
	struct ListNode * p1;
	for(p1=head; p1!=NULL; p1=p1->next)
	{
		count++;
	}
	return count;
}

struct ListNode * stepLL(struct ListNode *head, int step)
{
	for(step=step; step>0; step--)
	{
		if(head->next == NULL)
			return head;
		head = head->next;
	}
	return head;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *a = headA;
	struct ListNode *b = headB;

	int countA = lenLL(headA);
	int countB = lenLL(headB);
	int shorterLength;

	printf("%d, %d, %d\n", countA, countB, shorterLength);

	if (countA > countB)
	{
		headA = stepLL(headA, countA - countB);
		shorterLength = countB;
	}
	else if(countB > countA)
	{
		headB = stepLL(headB, countB - countA);
		shorterLength = countA;
	}
		printf("step: %d\n", shorterLength);

	for(shorterLength=shorterLength;shorterLength>0;shorterLength--)
	{
		printf("step: %d\n", shorterLength);
		if(headA->next == headB->next)
		{
			return headA->next;
		}
		headA = headA->next;
		headB = headB->next;
	}

	return NULL;
}

int main()
{
	struct ListNode * headA = initLL(1);
	struct ListNode * headB = initLL(2);

	struct ListNode * ptrA = appendLLpre(headA, 3);
	struct ListNode * ptrB = appendLLpre(headB, 4);

	ptrA = appendLLpre(ptrA, 5);
	ptrA = appendLLpre(ptrA, 7);
	ptrA = appendLLpre(ptrA, 9);
	ptrA = appendLLpre(ptrA, 11);
	ptrA = appendLLpre(ptrA, 13);
	ptrA = appendLLpre(ptrA, 15);
	ptrA = appendLLpre(ptrA, 17);
	ptrA = appendLLpre(ptrA, 19);
	ptrA = appendLLpre(ptrA, 21);
	ptrA = appendLLpre(ptrA, 23);
	ptrA = appendLLpre(ptrA, 25);
	ptrA = appendLLpre(ptrA, 27);
	ptrA = appendLLpre(ptrA, 29);
	ptrA = appendLLpre(ptrA, 31);
	ptrA = appendLLpre(ptrA, 33);
	ptrA = appendLLpre(ptrA, 35);
	ptrA = appendLLpre(ptrA, 37);
	ptrA = appendLLpre(ptrA, 39);

	ptrB = appendLLpre(ptrB, 6);
	ptrB = appendLLpre(ptrB, 8);
	ptrB = appendLLpre(ptrB, 10);
	ptrB = appendLLpre(ptrB, 12);
	ptrB = appendLLpre(ptrB, 14);
	ptrB = appendLLpre(ptrB, 16);
	ptrB = appendLLpre(ptrB, 18);
	ptrB = appendLLpre(ptrB, 20);
	ptrB = appendLLpre(ptrB, 22);
	ptrB = appendLLpre(ptrB, 24);
	ptrB = appendLLpre(ptrB, 26);
	ptrB = appendLLpre(ptrB, 28);
	ptrB = appendLLpre(ptrB, 30);
	ptrB = appendLLpre(ptrB, 32);
	ptrB = appendLLpre(ptrB, 34);
	ptrB = appendLLpre(ptrB, 36);
	ptrB = appendLLpre(ptrB, 38);
	ptrB = appendLLpre(ptrB, 40);

	ptrA = appendLLpre(ptrA, 41);
	ptrB->next = ptrA;

	ptrA = appendLLpre(ptrA, 42);

	print_r(headA);
	print_r(headB);

	struct ListNode * intersectionNode = getIntersectionNode(headA, headB);
	if(intersectionNode == NULL)
	{
		printf("output: NULL\n");
	}
	else
	{
		printf("[%d]\n", intersectionNode->val );
	}
	return 0;
}
