class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> pNum(n - 1, 1);
    	for (int i = 1; i < n - 1; ++i)
    		pNum[i] = (i + 1) * pNum[i - 1];
    	bool used[10];
    	memset(used, false, sizeof(used));
    	string result = "";
    	for (int i = 0; i < n - 1; ++i)
    	{
    		int num = pNum[n - 2 - i];
    		int pos = ceil((float)k / num);
    		k -= num * (pos - 1);
    		int j;
    		for (j = 1; j <= n && pos; ++j)
    		{
    			if (!used[j])
    				pos--;
    			if (!pos)
    				break;
    		}
    		used[j] = true;
    		result += '0' + j;
    	}
    	for (int i = 1; i <= n; ++i)
    		if (!used[i])
    		{
    			result += '0' + i;
    			break;
    		}
    	return result;
    }
};