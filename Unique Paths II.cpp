class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m, n;
        if ((m = obstacleGrid.size()) == 0 || (n = obstacleGrid[0].size()) == 0)
            return 0;
        int **paths = new int*[m];
        for (int i = 0; i < m; ++i)
            paths[i] = new int[n];
        paths[0][0] = obstacleGrid[0][0] == 1? 0: 1;
        for (int i = 1; i < n; ++i)
        {
            if (obstacleGrid[0][i] == 0 && paths[0][i - 1] == 1)
                paths[0][i] = 1;
            else
                paths[0][i] = 0;
        }
        for (int i = 1; i < m; ++i)
        {
            if (obstacleGrid[i][0] == 0 && paths[i - 1][0] == 1)
                paths[i][0] = 1;
            else
                paths[i][0] = 0;
        }
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
            {
                paths[i][j] = 0;
                if (obstacleGrid[i][j] == 1)
                    continue;
                if (paths[i - 1][j])
                    paths[i][j] += paths[i - 1][j];
                if (paths[i][j - 1])
                    paths[i][j] += paths[i][j - 1];
            }
        int result = paths[m - 1][n - 1];
        for (int i = 0; i < m; ++i)
            delete []paths[i];
        delete []paths;
        return result;
    }
};