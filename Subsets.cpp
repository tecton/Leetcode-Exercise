class Solution {
public:
    void constructSet(vector<int> &S, int start, vector<vector<int> > &result, vector<int> current)
    {
        if (start == S.size())
        {
            result.push_back(current);
            return;
        }
        constructSet(S, start + 1, result, current);
        if (!(current.size() > 0 && S[start] == current[current.size() - 1]))
        {
            current.push_back(S[start]);
            constructSet(S, start + 1, result, current);
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> current;
        sort(S.begin(), S.end());
        constructSet(S, 0, result, current);
        return result;
    }
};