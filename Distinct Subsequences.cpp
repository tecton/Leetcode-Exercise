class Solution {
public:
    int numDistinct(string S, string T) {
        int sn = S.length(), tn = T.length();
    	if (tn > sn)
    		return 0;
    	vector<int> prev, cur(sn + 1, 1);
    	for (int i = 0; i < tn; ++i)
    	{
    		prev = cur;
    		cur = vector<int>(sn + 1, 0);
    		for (int j = 1; j <= sn; ++j)
    			cur[j] = cur[j - 1] + (S[j - 1] == T[i] ? prev[j - 1]: 0);
    	}
    	return cur[sn];
    }
};