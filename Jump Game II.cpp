class Solution {
public:
    int jump(int A[], int n) {
        if (n < 2)
    		return 0;
    	int pos = 0;
    	int steps = 0, searchRange, nextPos, farPos;
    	while (pos < n - 1)
    	{
    		searchRange = A[pos];
    		farPos = nextPos = pos;
    		if (pos + searchRange >= n - 1)
    		    return steps + 1;
    		for (int i = 1; i <= searchRange; ++i)
    		{
    			if (pos + i + A[pos + i] >= n - 1)
    				return steps + 2;
    			if (pos + i + A[pos + i] > farPos)
    			{
    				farPos = pos + i + A[pos + i];
    				nextPos = pos + i;
    			}
    		}
    		if (nextPos == pos)
    			return -1;
    		pos = nextPos;
    		steps++;
    	}
    	return steps;
    }
};