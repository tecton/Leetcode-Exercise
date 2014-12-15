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
    void dfs(int &sum, TreeNode *root, int curVal)
    {
        if (root == NULL)
            return;
        int newVal = curVal * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
            sum += newVal;
        dfs(sum, root->left, newVal);
        dfs(sum, root->right, newVal);
    }
    int sumNumbers(TreeNode *root) {
        int sum = 0, curVal = 0;
        dfs(sum, root, curVal);
        return sum;
    }
};