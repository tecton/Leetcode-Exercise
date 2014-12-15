class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> >result;
        if (numRows == 0)
            return result;
        result.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; ++i)
        {
            vector<int> level;
            level.push_back(1);
            for (int j = 0; j < result[i - 1].size() - 1; ++j)
                level.push_back(result[i - 1][j] + result[i - 1][j + 1]);
            level.push_back(1);
            result.push_back(level);
        }
        return result;
    }
};