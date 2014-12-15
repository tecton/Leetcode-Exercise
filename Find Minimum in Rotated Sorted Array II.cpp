class Solution {
public:
    int findMin(vector<int> &num) {
        int start = 0, end = num.size() - 1, middle;
    	while (start < end)
    	{
    		if (num[start] < num[end])
    		{
    			return num[start];
    		}
    		middle = (start + end) / 2;
    		if (num[middle] > num[start])
    			start = middle + 1;
    		else if (num[middle] < num[start])
    			end = middle;
    		else
    			start++;
    	}
    	return num[start];
    }
};