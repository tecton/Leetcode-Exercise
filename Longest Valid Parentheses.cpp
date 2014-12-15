class Solution {
public:
    int longestValidParentheses(string s) {
        int toMatch = 0, result = 0;
        int n = (int)s.length();
        if (n == 0)
            return 0;
    	vector<int> index;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
    			index.push_back(i);
            else
            {
                if (!index.empty() && s[index.back()] == '(')
    			{
    				int leftPos = -1;
    				index.pop_back();
    				if (!index.empty())
    					leftPos = index.back();
    				result = max(result, i - leftPos);
    			}
    			else
    				index.push_back(i);
            }
        }
        return result;
    }
};