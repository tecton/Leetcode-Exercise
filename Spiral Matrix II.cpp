class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result;
        for (int i = 0; i < n; ++i)
        {
            vector<int> v(n, 0);
            result.push_back(v);
        }
        n = abs(n);
        if (n == 0)
            return result;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int fillNum = 1;
        while (left <= right && top <= bottom)
        {
            for (int j = left; j <= right; ++j)
                result[top][j] = fillNum++;
            for (int i = top + 1; i <= bottom; ++i)
                result[i][right] = fillNum++;
            if (bottom > top)
    			for (int j = right - 1; j >= left; --j)
    				result[bottom][j] = fillNum++;
    		if (right > left)
    			for (int i = bottom - 1; i > top; --i)
    				result[i][left] = fillNum++;
            left++;
            right--;
            bottom--;
            top++;
        }
        return result;
    }
};