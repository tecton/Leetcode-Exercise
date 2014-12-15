class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int m, n;
        if ((m = matrix.size()) == 0 || (n = matrix[0].size()) == 0)
            return result;
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (left <= right && top <= bottom)
        {
            for (int j = left; j <= right; ++j)
                result.push_back(matrix[top][j]);
            for (int i = top + 1; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
            if (bottom > top)
    			for (int j = right - 1; j >= left; --j)
    				result.push_back(matrix[bottom][j]);
    		if (right > left)
    			for (int i = bottom - 1; i > top; --i)
    				result.push_back(matrix[i][left]);
            left++;
            right--;
            bottom--;
            top++;
        }
        return result;
    }
};