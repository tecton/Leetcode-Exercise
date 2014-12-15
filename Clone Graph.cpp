/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, map<int, UndirectedGraphNode *> &clonedNodes)
    {
        if (node == NULL)
            return NULL;
        UndirectedGraphNode *cloned;
        map<int, UndirectedGraphNode*>::iterator it;
        it = clonedNodes.find(node->label);
        if (it != clonedNodes.end())
        {
            cloned = it->second;
            return cloned;
        }
        else
        {
            cloned = new UndirectedGraphNode(node->label);
            clonedNodes.insert(make_pair(node->label, cloned));
        }
        for (int i = 0; i < node->neighbors.size(); ++i)
        {
            cloned->neighbors.push_back(dfs(node->neighbors[i], clonedNodes));
        }
        return cloned;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode*> clonedNodes;
        return dfs(node, clonedNodes);
    }
};