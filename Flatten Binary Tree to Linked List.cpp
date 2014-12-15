/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *getPreNode(TreeNode *root)
	{
		if (root == NULL)
			return NULL;
		if (!root->left && !root->right)
			return root;
		TreeNode *pre;
		if (root->right)
			pre = getPreNode(root->right);
		else
			pre = getPreNode(root->left);
		if (root->left)
		{
			getPreNode(root->left)->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		return pre;
	}
	void flatten(TreeNode *root) {
		getPreNode(root);
	}
};