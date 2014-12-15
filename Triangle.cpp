class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        if (row == 1)
            return triangle[0][0];
        vector<int> preMinSums;
        preMinSums.push_back(triangle[0][0]);
        int result = INT_MAX;
        for (int i = 1; i < row; ++i)
        {
            vector<int> minSums;
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0)
                    minSums.push_back(triangle[i][j] + preMinSums[j]);
                else if (j == i)
                    minSums.push_back(triangle[i][j] + preMinSums[j - 1]);
                else
                    minSums.push_back(min(preMinSums[j - 1], preMinSums[j]) + triangle[i][j]);
            }
            preMinSums = minSums;
        }
        for (int i = 0; i < row; ++i)
            result = min(result, preMinSums[i]);
        return result;
    }
};