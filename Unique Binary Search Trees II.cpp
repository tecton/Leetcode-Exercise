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
    vector<TreeNode *> generateTrees(int start, int end)
    {
    	vector<TreeNode *> result;
    	if (start >= end)
    	{
    		result.push_back(NULL);
    		return result;
    	}
    	for (int i = 0; i < end - start; ++i)
    	{
    		TreeNode *root;
    		vector<TreeNode *> leftNodes = generateTrees(start, start + i);
    		vector<TreeNode *> rightNodes = generateTrees(start + i + 1, end);
    		for (int m = 0; m < leftNodes.size(); ++m)
    			for (int n = 0; n < rightNodes.size(); ++n)
    			{
    				root = new TreeNode(start + i);
    				root->left = leftNodes[m];
    				root->right = rightNodes[n];
    				result.push_back(root);
    			}
    	}
    	return result;
    }
    
    vector<TreeNode *> generateTrees(int n) {
    	return generateTrees(1, n + 1);
    }
};