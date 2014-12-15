class Solution {
public:
    void dfsBoard(vector<vector<char> > &board, int row, int col)
    {
        int dir[] = {0, 1, 0, -1, -1, 0, 1, 0};
        queue<pair<int, int> > q;
        for (int i = 0; i < row; ++i)
        {
            if (board[i][0] == 'O')
                q.push(make_pair(i, 0));
            if (board[i][col - 1] == 'O')
                q.push(make_pair(i, col - 1));
        }
        for (int j = 0; j < col; ++j)
        {
            if (board[0][j] == 'O')
                q.push(make_pair(0, j));
            if (board[row - 1][j] == 'O')
                q.push(make_pair(row - 1, j));
        }
        while (!q.empty())
        {
            pair<int, int> coord = q.front();
            q.pop();
			if (board[coord.first][coord.second] == '#')
				continue;
            board[coord.first][coord.second] = '#';
            for (int k = 0; k < 4; ++k)
            {
                int x = coord.first + dir[2 * k];
                int y = coord.second + dir[2 * k + 1];
                if (x >= 0 && x < row && y >= 0 && y < col && board[x][y] == 'O')
                    q.push(make_pair(x, y));
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        int row, col;
        if ((row = board.size()) == 0 || (col = board[0].size()) == 0)
            return;
        dfsBoard(board, row, col);
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
    }
};