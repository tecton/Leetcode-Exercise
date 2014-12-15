class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        string result = "";
        int minLength = INT_MAX;
        for (int i = 0; i < strs.size(); ++i)
            minLength = min(minLength, (int)strs[i].size());
        for (int i = 0; i < minLength; ++i)
        {
            int j = 1;
            for (; j < strs.size(); ++j)
            {
                if (strs[j][i] != strs[0][i])
                    break;
            }
            if (j != strs.size())
                break;
            result += strs[0][i];
        }
        return result;
    }
};