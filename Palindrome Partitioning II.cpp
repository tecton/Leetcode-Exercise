class Solution {
public:
    int minCut(string s) {
        int n = s.length();
    	if (n < 2)
    		return 0;
    	vector<int> cuts(n + 1, 0);
    	for (int i = 0; i <= n; ++i)
    		cuts[i] = i - 1;
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j)
    			cuts[i + j + 1] = min(cuts[i + j + 1], cuts[i - j] + 1);
    		for (int j = 0; i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1]; ++j)
    			cuts[i + j + 2] = min(cuts[i + j + 2], cuts[i - j] + 1);
    	}
    	return cuts[n];
    }
};