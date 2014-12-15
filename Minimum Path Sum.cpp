class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m, n;
        if ((m = grid.size()) == 0 || (n = grid[0].size()) == 0)
            return 0;
        vector<int> result(n, 0);
        vector<int> lastRow;
        result[0] = grid[0][0];
        for (int j = 1; j < n; ++j)
            result[j] = result[j - 1] + grid[0][j];
        for (int i = 1; i < m; ++i)
        {
            lastRow = result;
            result[0] = grid[i][0] + lastRow[0];
            for (int j = 1; j < n; ++j)
                result[j] = min(result[j - 1], lastRow[j]) + grid[i][j];
        }
        return result[n - 1];
    }
};