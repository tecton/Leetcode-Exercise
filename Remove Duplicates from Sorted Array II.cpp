class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int reader = 0, writer = 0;
    	while (reader != n)
    	{
    		if (reader < n - 2 && A[reader] == A[reader + 1] && A[reader] == A[reader + 2])
    			reader++;
    		else
    			A[writer++] = A[reader++];
    	}
    	return writer;
    }
};