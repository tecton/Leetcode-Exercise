class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0)
    		return 0;
    	int level = 0, block = 0, all = 0;
    	int l = 0, r = n - 1;
    	while (l <= r)
    	{
    		if (min(A[l], A[r]) > level)
    		{
    			all += (min(A[l], A[r]) - level) * (r - l + 1);
    			level = min(A[l], A[r]);
    		}
    		if (A[l] < A[r])
    			block += A[l++];
    		else
    			block += A[r--];
    	}
    	return all - block;
    }
};