#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void print_r(struct ListNode * a) {
	while(a != NULL) {
		printf("%d ", a->val);
		a = a->next;
	}
	printf("\n");
}

struct ListNode * addNode (struct ListNode * a, int val) {
	struct ListNode * node = calloc(1, sizeof(struct ListNode));
	node->val = val;
	node->next = a;
	return node;
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
	struct ListNode * root = NULL;
	struct ListNode * head = NULL;
	while(1) {
		//printf("%d %d\n", l1->val, l2->val);
		if(l1 == NULL && l2 == NULL) {
			printf("case 1\n");
			break;
		} else if(l1 == NULL) {
			printf("case 2\n");
			if(root == NULL) {
				root = l2;
				head = l2;
			} else {
				root->next = l2;
				root = root->next;
			}
			l2 = l2->next;
		} else if(l2 == NULL) {
			printf("case 3\n");
			if(root == NULL) {
				root = l1;
				head = l1;
			} else {
				root->next = l1;
				root = root->next;
			}
			l1 = l1->next;
		} else if(l2->val > l1->val) {
			printf("case 4\n");
			if(root == NULL) {
				root = l1;
				head = l1;
			} else {
				root->next = l1;
				root = root->next;
			}
			l1 = l1->next;
		} else if(l2->val <= l1->val) {
			printf("case 5\n");
			if(root == NULL) {
				root = l2;
				head = l2;
			} else {
				root->next = l2;
				root = root->next;
			}
			l2 = l2->next;
		}
	}
	return head;
}

int main() {
	struct ListNode * a = NULL;
	a = addNode(a, 3);
	a = addNode(a, 3);
	a = addNode(a, 2);
	a = addNode(a, 1);
	a = addNode(a, 1);

	struct ListNode * b = NULL;
	b = addNode(b, 3);
	b = addNode(b, 3);
	b = addNode(b, 2);
	b = addNode(b, 1);
	b = addNode(b, 1);

	struct ListNode * c = mergeTwoLists(a, b);
	print_r(c);
	return 0;
}
