class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0)
    		return true;
    	vector<bool> isWord(s.size() + 1, false);
    	isWord[0] = true;
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (isWord[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    isWord[i] = true;
                    break;
                }
            }
        }
        return isWord[s.size()];
    }
};