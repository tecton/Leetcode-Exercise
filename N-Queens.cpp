class Solution {
public:
    void dfs(vector<vector<string> > &result, vector<string> &board,
    	     vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2, int row, int &n)
    {
    	if (row == n)
    	{
    		result.push_back(board);
    		return;
    	}
    	for (int c = 0; c < n; ++c)
    	{
    		if (!col[c] && !diag1[c + row] && !diag2[c - row + n])
    		{
    			col[c] = diag1[c + row] = diag2[c - row + n] = true;
    			board[row][c] = 'Q';
    			dfs(result, board, col, diag1, diag2, row + 1, n);
    			col[c] = diag1[c + row] = diag2[c - row + n] = false;
    			board[row][c] = '.';
    		}
    	}
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
    	if (n == 0)
    		return result;
    	vector<string> board(n, string(n, '.'));
    	vector<bool> col(n, false), diag1(2 * n, false), diag2(2 * n, false);
    	dfs(result, board, col, diag1, diag2, 0, n);
    	return result;
    }
};