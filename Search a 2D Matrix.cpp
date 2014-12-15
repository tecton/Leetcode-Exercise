class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m, n;
        if ((m = matrix.size()) == 0 || (n = matrix[0].size()) == 0)
            return false;
        int start = 0, end = m * n - 1, middle, value;
        while (start < end)
        {
            middle = (start + end) / 2;
            value = matrix[middle / n][middle % n];
            if (target == value)
                return true;
            else if (target < value)
                end = middle - 1;
            else
                start = middle + 1;
        }
        if (matrix[start / n][start % n] == target)
            return true;
        return false;
    }
};