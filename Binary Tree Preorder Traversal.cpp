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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *currentNode = root;
        while (currentNode != NULL)
        {
            if (currentNode->left == NULL)
            {
                result.push_back(currentNode->val);
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
                    result.push_back(currentNode->val);
                    currentNode = currentNode->left;
                }
                else
                {
                    preNode->right = NULL;
                    currentNode = currentNode->right;
                }
            }
        }
        return result;
    }
};