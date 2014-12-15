class Solution {
private:
    int row, col;
public:
    bool dfs(int i, int j, string &word, int index, vector<vector<char> > &board, bool searched[500][500])
    {
        if (index == word.length())
            return true;
        searched[i][j] = true;
        if (i - 1 >= 0 && !searched[i - 1][j] && board[i - 1][j] == word[index] && dfs(i - 1, j, word, index + 1, board, searched))
            return true;
        if (i + 1 < row && !searched[i + 1][j] && board[i + 1][j] == word[index] && dfs(i + 1, j, word, index + 1, board, searched))
            return true;
        if (j - 1 >= 0 && !searched[i][j - 1] && board[i][j - 1] == word[index] && dfs(i, j - 1, word, index + 1, board, searched))
            return true;
        if (j + 1 < col && !searched[i][j + 1] && board[i][j + 1] == word[index] && dfs(i, j + 1, word, index + 1, board, searched))
            return true;
        searched[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        if (word == "")
            return true;
        if ((row = board.size()) == 0 || (col = board[0].size()) == 0)
            return false;
        bool searched[500][500];
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == word[0])
                {
                    memset(searched, 0, sizeof(searched));
                    if (dfs(i, j, word, 1, board, searched))
                        return true;
                }
            }
        return false;
    }
};