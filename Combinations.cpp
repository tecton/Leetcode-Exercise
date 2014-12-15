class Solution {
public:
    void combineDFS(vector<vector<int> > &result, vector<int> &cur, int n, int k, int start)
    {
        if (cur.size() == k)
            result.push_back(cur);
        else
        {
            for (int i = start; i <= n; ++i)
            {
                cur.push_back(i);
                combineDFS(result, cur, n, k, i + 1);
                cur.pop_back();
            }
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >result;
        if (k == 0)
            return result;
        vector<int> cur;
        combineDFS(result, cur, n, k, 1);
        return result;
    }
};