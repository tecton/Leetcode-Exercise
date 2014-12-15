class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length();
    	if (l1 + l2 != s3.length())
    		return false;
    	vector<vector<bool> > dp(l1 + 1, vector<bool>(l2 + 1, false));
    	dp[0][0] = true;
    	for (int i = 1; i <= l1; ++i)
    	{
    		if (dp[i - 1][0] && s1[i - 1] == s3[i - 1])
    			dp[i][0] = true;
    	}
    	for (int j = 1; j <= l2; ++j)
    	{
    		if (dp[0][j - 1] && s2[j - 1] == s3[j - 1])
    			dp[0][j] = true;
    	}
    	for (int i = 1; i <= l1; ++i)
    	{
    		for (int j = 1; j <= l2; ++j)
    		{
    			if ((dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
    				|| (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]))
    				dp[i][j] = true;
    		}
    	}
    	return dp[l1][l2];
    }
};