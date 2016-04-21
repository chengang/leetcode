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

bool isEq(struct TreeNode *a, struct TreeNode *b) {
	if (a == NULL && b == NULL) {
		return true;
	}
	else if (a != NULL && b == NULL) {
		return false;
	}
	else if (a == NULL && b != NULL) {
		return false;
	}
	else {
		return a->val == b->val && isEq(a->left, b->right) && isEq(a->right, b->left);
	}
}

bool isSymmetric(struct TreeNode *root) {
	if (root == NULL)
		return true;
	return isEq(root->left, root->right);
}

int main() {
	struct TreeNode * root = initRoot(1);
	struct TreeNode * node_l = addLeft(root, 2);
	struct TreeNode * node_r = addRight(root, 2);
	struct TreeNode * node_ll = addLeft(node_l, 3);
	struct TreeNode * node_lr = addRight(node_l, 4);
	struct TreeNode * node_rl = addLeft(node_r, 4);
	struct TreeNode * node_rr = addRight(node_r, 3);

	//printf("%d\n", root->left->left->right->val);
	//printf("%d\n", root->right->right->right->val);

	if (isSymmetric(root)) {
		printf("true\n");
	} else {
		printf("false\n");
	}

	return 0;
}
