class Solution {
public:
    bool dfs(vector<vector<char> > &board, int g, bool rows[9][9], bool cols[9][9], bool grids[9][9])
    {
    	int r = g / 9, c = g % 9;
    	while (g < 81 && board[r][c] != '.')
    	{
    		g++;
    		r = g / 9;
    		c = g % 9;
    	}
    	if (g >= 81)
    		return true;
    	for (int i = 1; i <= 9; ++i)
    	{
    		if (!rows[r][i - 1] && !cols[c][i - 1] && !grids[3 * (r / 3) + (c / 3)][i - 1])
    		{
    			board[r][c] = '0' + i;
    			rows[r][i - 1] = cols[c][i - 1] = grids[3 * (r / 3) + (c / 3)][i - 1] = true;
    			if (dfs(board, g + 1, rows, cols, grids))
    				return true;
    			rows[r][i - 1] = cols[c][i - 1] = grids[3 * (r / 3) + (c / 3)][i - 1] = false;
    		}
    	}
    	// set back
    	board[r][c] = '.';
    	return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        bool rows[9][9], cols[9][9], grids[9][9];
    	memset(rows, false, sizeof(rows));
    	memset(cols, false, sizeof(cols));
    	memset(grids, false, sizeof(grids));
    	for (int r = 0; r < 9; ++r)
    		for (int c = 0; c < 9; ++c)
    		{
    			if (board[r][c] != '.')
    				rows[r][board[r][c] - '1'] = cols[c][board[r][c] - '1'] = grids[3 * (r / 3) + (c / 3)][board[r][c] - '1'] = true;
    		}
    	dfs(board, 0, rows, cols, grids);
    }
};