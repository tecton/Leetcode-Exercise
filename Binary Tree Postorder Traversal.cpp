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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL)
            return result;
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        while (!treeStack.empty())
        {
            TreeNode *cur = treeStack.top();
            treeStack.pop();
            if (cur->left == NULL && cur->right == NULL)
                result.push_back(cur->val);
            else
            {
                TreeNode *l = cur->left, *r = cur->right;
                cur->left = NULL;
                cur->right = NULL;
                treeStack.push(cur);
                if (r)
                    treeStack.push(r);
                if (l)
                    treeStack.push(l);
            }
        }
        return result;
    }
};