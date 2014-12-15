class Solution {
public:
    void dfs(vector<string> &result, string s, int index, string current)
    {
        if (s == "")
			return;
        if (index == 3)
        {
            int num = atoi(s.c_str());
			if (s.size() > 1 && s[0] == '0')
				return;
            if (num >= 0 && num < 256)
            {
                current += s;
                result.push_back(current);
            }
            return;
        }
        for (int i = 1; i < min(4, (int)s.size()); ++i)
        {
            if (s.substr(i).size() > 3 * (3 - index) && s.substr(i).size() < (3 - index))
                continue;
			string numStr = s.substr(0, i);
			if (numStr.size() > 1 && numStr[0] == '0')
				continue;
            int num = atoi(numStr.c_str());
            if (num >= 0 && num < 256)
                dfs(result, s.substr(i), index + 1, current + s.substr(0, i) + ".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        dfs(result, s, 0, "");
        return result;
    }
};