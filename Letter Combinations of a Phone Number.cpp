class Solution {
public:
    void dfs(string digits, map<char, string> &mapping, vector<string> &result, string current)
    {
        if (digits.size() == 0)
        {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < mapping[digits[0]].size(); ++i)
        {
            current += mapping[digits[0]][i];
            dfs(digits.substr(1), mapping, result, current);
            current = current.substr(0, current.size() - 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char, string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
        
        vector<string> result;
        dfs(digits, mapping, result, "");
        return result;
    }
};