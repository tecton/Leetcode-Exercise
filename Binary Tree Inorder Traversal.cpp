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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> nodeQ;
        nodeQ.push(root);
        while (!nodeQ.empty())
        {
            TreeNode *node = nodeQ.top();
            nodeQ.pop();
            if (node == NULL)
                continue;
            if (node->left == NULL && node->right == NULL)
                result.push_back(node->val);
            else
            {
                if (node->right != NULL)
                {
                    nodeQ.push(node->right);
                    node->right = NULL;
                }
                if (node->left != NULL)
                {
                    TreeNode *leftNode = node->left;
                    node->left = NULL;
                    nodeQ.push(node);
                    nodeQ.push(leftNode);
                }
                else
                {
                    nodeQ.push(node);
                }
            }
        }
        return result;
    }
};