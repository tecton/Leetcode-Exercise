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
private:
    int target;
public:
    void dfs(vector<vector<int> > &result, vector<int> current, int sum, TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            if (sum + root->val == target)
            {
                current.push_back(root->val);
                result.push_back(current);
            }
            return;
        }
        current.push_back(root->val);
        dfs(result, current, sum + root->val, root->left);
        dfs(result, current, sum + root->val, root->right);
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> current;
        target = sum;
        dfs(result, current, 0, root);
        return result;
    }
};