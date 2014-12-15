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
    void dfs(TreeNode *root, int &result)
    {
        int maxPath = root->val;
        if (root->left != NULL)
        {
            dfs(root->left, result);
            maxPath = max(maxPath, root->left->val + root->val);
        }
        if (root->right != NULL)
        {
            dfs(root->right, result);
            maxPath = max(maxPath, root->right->val + root->val);
        }
        if (root->left && root->right)
            result = max(result, root->val + root->left->val + root->right->val);
        root->val = maxPath;
        result = max(result, root->val);
    }
    int maxPathSum(TreeNode *root) {
        int result = INT_MIN;
        if (root == NULL)
            return 0;
        dfs(root, result);
        return result;
    }
};