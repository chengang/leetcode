#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void print_r(struct ListNode * root) {
	while(root != NULL) {
		printf("%d ", root->val);
		root = root->next;
	}
	printf("\n");
}

struct ListNode * addNode (struct ListNode * root, int val) {
	struct ListNode * node = calloc(1, sizeof(struct ListNode));
	node->val = val;
	node->next = root;
	return node;
}

struct ListNode *deleteDuplicates(struct ListNode *head) {
	struct ListNode * node = head;
	while (node != NULL) {
		if (node->next != NULL && node->val == node->next->val)
			node->next = node->next->next;
		else
			node = node->next;
	}
	return head;
}

int main() {
	struct ListNode * root = NULL;
	root = addNode(root, 3);
	root = addNode(root, 3);
	root = addNode(root, 2);
	root = addNode(root, 1);
	root = addNode(root, 1);

	root = deleteDuplicates(root);
	print_r(root);
	return 0;
}
