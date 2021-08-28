#include "stdafx.h"

//**
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	vector<TreeNode> children(vector<TreeNode> const &root)
	{
		vector<TreeNode> c;
		for (auto i:root)
		{
			if (i.right)
				c.push_back(*i.right);

			if (i.left)
				c.push_back(*i.left);
		}
		return move(c);
	}

	int leftMost(vector<TreeNode> const &root)
	{
		return root[0].val;
	}

public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int>	c;
		if (!root)
			return c;
		for (vector<TreeNode> v = { *root }; !v.empty(); v = children(v))
		{
			c.push_back(leftMost(v));
		}
		return move(c);
	}
};
