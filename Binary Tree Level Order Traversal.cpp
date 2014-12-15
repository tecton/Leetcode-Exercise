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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL)
            return result;
        queue<TreeNode*> nodeQueue;
        TreeNode *levelEnd = new TreeNode(0);
        levelEnd->left = levelEnd;
        nodeQueue.push(root);
        nodeQueue.push(levelEnd);
        vector<int> level;
        
        while (!nodeQueue.empty())
        {
            TreeNode *cur = nodeQueue.front();
            nodeQueue.pop();
            if (cur == NULL)
                continue;
            if (cur->val == 0 && cur->left == cur)
            {
                if (!level.empty())
                    result.push_back(level);
                level.clear();
                if (!nodeQueue.empty())
                {
                    nodeQueue.push(cur);
                    continue;
                }
                else
                    break;
            }
            level.push_back(cur->val);
            nodeQueue.push(cur->left);
            nodeQueue.push(cur->right);
        }
        return result;
    }
};