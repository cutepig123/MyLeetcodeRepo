#include "stdafx.h"

//**
// Definition for binary tree with next pointer.
 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
	// return leftmost & rightmost children
	void connect(TreeLinkNode *root, TreeLinkNode **leftMost, TreeLinkNode **rightMost) {
		if (!root)
			return;

		if (root->left)
		{
			root->left->next = root->right;
		}

		if (root->right)
		{
			root->right->next = NULL;
		}

		if (root->left)
		{
			*leftMost = root->left;
		}
		else
		{
			*leftMost = root->right;
		}

		if (root->right)
		{
			*rightMost = root->right;
		}
		else
		{
			*rightMost = root->left;
		}

		TreeLinkNode *n1 = 0;
		TreeLinkNode *n2 = 0;
		TreeLinkNode *n3 = 0;
		TreeLinkNode *n4 = 0;

		if (root->left)
			connect(root->left, &n1, &n2);

		if (root->right)
			connect(root->right, &n3, &n4);

		if (n2 && n3)
			n2->next = n3;
	}
public:
	void connect(TreeLinkNode *root) {
		

		TreeLinkNode *n1 = 0;
		TreeLinkNode *n2 = 0;
		connect(root, &n1, &n2);
	}
};
