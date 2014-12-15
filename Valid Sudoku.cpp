class Solution {
public:
    bool setMask(bool mask[], char index)
    {
        if (index == '.')
            return true;
        if (mask[index - '0'] == true)
            return false;
        return mask[index - '0'] = true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        bool mask1[10], mask2[10];
        for (int i = 0; i < 9; ++i)
        {
            memset(mask1, 0, sizeof(mask1));
            memset(mask2, 0, sizeof(mask2));
            for (int j = 0; j < 9; ++j)
            {
                if (setMask(mask1, board[i][j]) == false)
                    return false;
                if (setMask(mask2, board[j][i]) == false)
                    return false;
            }
        }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                memset(mask1, 0, sizeof(mask1));
                for (int m = 0; m < 3; ++m)
                    for (int n = 0; n < 3; ++n)
                        if (setMask(mask1, board[3 * i + m][3 * j + n]) == false)
                            return false;
            }
        return true;
    }
};