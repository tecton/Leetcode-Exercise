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
    void recoverTree(TreeNode *root) {
        TreeNode *currentNode = root, *bigger = NULL, *smaller = NULL, *prev = NULL;
    	while (currentNode != NULL)
    	{
    		if (currentNode->left == NULL)
    		{
    			if (prev && prev->val >= currentNode->val)
    			{
    				if (!bigger)
    					bigger = prev;
    				smaller = currentNode;
    			}
    			prev = currentNode;
    			currentNode = currentNode->right;
    		}
    		else
    		{
    			TreeNode *preNode = currentNode->left;
    			while (preNode->right && preNode->right != currentNode)
    				preNode = preNode->right;
    			if (preNode->right == NULL)
    			{
    				preNode->right = currentNode;
    				currentNode = currentNode->left;
    			}
    			else
    			{
    				preNode->right = NULL;
    				if (prev && prev->val >= currentNode->val)
    				{
    					if (!bigger)
    						bigger = prev;
    					smaller = currentNode;
    				}
    				prev = currentNode;
    				currentNode = currentNode->right;
    			}
    		}
    	}
    	int temp = bigger->val;
    	bigger->val = smaller->val;
    	smaller->val = temp;
    }
};