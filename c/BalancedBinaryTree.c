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

bool isBalanced(struct TreeNode *root) {
	if (root == NULL)
		return true;

	if (root->left == NULL && root->right == NULL) {
		return true;
	} else {
		int hl = height(root->left);
		int hr = height(root->right);
		bool bBalanced = true;
		if (hl - hr > 1 || hr - hl > 1)
			bBalanced = false;
		return bBalanced && isBalanced(root->left) && isBalanced(root->right);
	}
}

int main() {
	struct TreeNode * root = initRoot(5);
	struct TreeNode * node_l = addLeft(root, 4);
	struct TreeNode * node_r = addRight(root, 8);
	struct TreeNode * node_ll = addLeft(node_l, 11);
	struct TreeNode * node_rl = addLeft(node_r, 13);
	struct TreeNode * node_rr = addRight(node_r, 4);
	struct TreeNode * node_lll = addLeft(node_ll, 7);
	struct TreeNode * node_llr = addRight(node_ll, 2);
	struct TreeNode * node_rrr = addRight(node_rr, 1);

	printf("%d\n", height(root));
	//printf("%d\n", root->left->left->right->val);
	//printf("%d\n", root->right->right->right->val);

	if(isBalanced(root)) {
		printf("true\n");
	} else {
		printf("false\n");
	}

	return 0;
}
