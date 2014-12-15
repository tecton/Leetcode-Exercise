class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool clearFirstRow = false;
        for (int j = 0; j < matrix[0].size(); ++j)
            if (matrix[0][j] == 0)
            {
                clearFirstRow = true;
                break;
            }
        for (int i = 1; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); ++i)
        {
            if (matrix[i][0] == 0)
            {
                fill(matrix[i].begin(), matrix[i].end(), 0);
                continue;
            }
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if(matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (clearFirstRow)
            fill(matrix[0].begin(), matrix[0].end(), 0);
    }
};