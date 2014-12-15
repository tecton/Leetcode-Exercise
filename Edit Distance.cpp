class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
    	int l2 = word2.length();
    	if (l1 == 0 || l2 == 0)
    		return max(l1, l2);
    	vector<vector<int> > editDistance(l1 + 1, vector<int>(l2 + 1, INT_MAX));
    	for (int j = 0; j <= l2; ++j)
    		editDistance[0][j] = j;
    	for (int i = 0; i <= l1; ++i)
    		editDistance[i][0] = i;
    	for (int i = 1; i <= l1; ++i)
    	{
    		for (int j = 1; j <= l2; ++j)
    		{
    			editDistance[i][j] = min((editDistance[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1)), editDistance[i][j - 1] + 1);
    			editDistance[i][j] = min(editDistance[i][j], editDistance[i - 1][j] + 1);
    		}
    	}
    	return editDistance[l1][l2];
    }
};