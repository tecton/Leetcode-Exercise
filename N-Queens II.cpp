class Solution {
public:
    void dfs(int &result, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2, int row, int &n)
    {
    	if (row == n)
    	{
    		result++;
    		return;
    	}
    	for (int c = 0; c < n; ++c)
    	{
    		if (!col[c] && !diag1[c + row] && !diag2[c - row + n])
    		{
    			col[c] = diag1[c + row] = diag2[c - row + n] = true;
    			dfs(result, col, diag1, diag2, row + 1, n);
    			col[c] = diag1[c + row] = diag2[c - row + n] = false;
    		}
    	}
    }
    int totalNQueens(int n) {
        int result = 0;
    	if (n == 0)
    		return 0;
    	vector<bool> col(n, false), diag1(2 * n, false), diag2(2 * n, false);
    	dfs(result, col, diag1, diag2, 0, n);
    	return result;
    }
};