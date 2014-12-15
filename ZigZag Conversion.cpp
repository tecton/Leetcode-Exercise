class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1)
			return s;
        vector<string> rows;
        for (int i = 0; i < nRows; ++i)
            rows.push_back("");
        int row = 0, dir = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            rows[row].push_back(s[i]);
            if (row == nRows - 1)
                dir = -1;
            if (row == 0)
                dir = 1;
			row += dir;
        }
        string result = "";
        for (int i = 0; i < nRows; ++i)
            result += rows[i];
        return result;
    }
};