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

bool hasPathSum(struct TreeNode *root, int sum) {
	if(!root)
		return false;
	if(root->left == NULL && root->right == NULL) {	
		if (sum - root->val == 0)
			return true;
		else
			return false;
	} else { 
		sum = sum - root->val;
		return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
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

	//printf("%d\n", root->left->left->right->val);
	//printf("%d\n", root->right->right->right->val);

	if(hasPathSum(root, 21)) {
		printf("true\n");
	} else {
		printf("false\n");
	}

	return 0;
}
