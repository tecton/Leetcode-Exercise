class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; ++i)
    	{
    		int cur = A[i];
    		if (cur == i + 1 || cur <= 0 || cur > n)
    			continue;
    		if (A[cur - 1] != cur)
    		{
    			int temp = A[cur - 1];
    			A[cur - 1] = cur;
    			A[i] = temp;
    			--i;
    		}
    	}
    	for (int i = 0; i < n; ++i)
    		if (A[i] != i + 1)
    			return i + 1;
    	return n + 1;
    }
};