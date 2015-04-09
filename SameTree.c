#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode * initRoot (int val) {
	struct TreeNode * root = calloc(1, sizeof(struct TreeNode));
	root->val = val;
	root->left = NULL;
	root->right = NULL;
	return root;
}

struct TreeNode * addLeft (struct TreeNode * parent, int val) {
	struct TreeNode * node = calloc(1, sizeof(struct TreeNode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;

	parent->left = node;
	return node;
}

struct TreeNode * addRight (struct TreeNode * parent, int val) {
	struct TreeNode * node = calloc(1, sizeof(struct TreeNode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;

	parent->right = node;
	return node;
}

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int height(struct TreeNode *root) {
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return 1 + max(height(root->left), height(root->right));
}

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
	if (p == NULL && q == NULL)
		return true;
	else if (p == NULL && q != NULL)
		return false;
	else if (p != NULL && q == NULL)
		return false;
	else 
		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
	struct TreeNode * p = initRoot(5);
	struct TreeNode * node_l = addLeft(p, 4);
	struct TreeNode * node_r = addRight(p, 8);
	struct TreeNode * node_ll = addLeft(node_l, 11);
	struct TreeNode * node_rl = addLeft(node_r, 13);
	struct TreeNode * node_rr = addRight(node_r, 4);
	struct TreeNode * node_lll = addLeft(node_ll, 7);
	struct TreeNode * node_llr = addRight(node_ll, 2);
	struct TreeNode * node_rrr = addRight(node_rr, 1);

	struct TreeNode * q = initRoot(5);
	node_l = addLeft(q, 4);
	node_r = addRight(q, 8);
	node_ll = addLeft(node_l, 11);
	node_rl = addLeft(node_r, 13);
	node_rr = addRight(node_r, 4);
	node_lll = addLeft(node_ll, 7);
	node_llr = addRight(node_ll, 2);
	node_rrr = addRight(node_rr, 11);

	//printf("%d\n", height(root));
	//printf("%d\n", root->left->left->right->val);
	//printf("%d\n", root->right->right->right->val);

	if(isSameTree(p, q)) {
		printf("true\n");
	} else {
		printf("false\n");
	}

	return 0;
}
