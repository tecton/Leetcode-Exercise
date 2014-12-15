class Solution {
public:
    bool isPalindrome(string &s, int end)
    {
        for (int i = 0; i <= end / 2; ++i)
            if (s[i] != s[end - i])
                return false;
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        if (s == "")
		{
			vector<string> empty;
			result.push_back(empty);
            return result;
		}
        for (int i = 0; i < s.length(); ++i)
        {
            if (isPalindrome(s, i))
            {
                vector<vector<string> > subResult = partition(s.substr(i + 1));
                for (int j = 0; j < subResult.size(); ++j)
                {
                    subResult[j].insert(subResult[j].begin(), s.substr(0, i + 1));
					result.push_back(subResult[j]);
                }
            }
        }
        return result;
    }
};