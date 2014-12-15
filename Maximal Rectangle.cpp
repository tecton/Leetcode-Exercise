class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
    	int result = 0;
        stack<int> index;
    	int i;
    	for (i = 0; i < height.size(); ++i)
    	{
    		if (index.empty() || height[index.top()] < height[i])
    		{
    			index.push(i);
    		}
    		else
    		{
    			while (!index.empty() && height[index.top()] > height[i])
    			{
    				int h = height[index.top()];
    				index.pop();
    				int l = index.empty() ? -1: index.top();
    				result = max(result, h * (i - l - 1));
    			}
    			index.push(i);
    		}
    	}
    	while (!index.empty())
    	{
    		while (!index.empty())
    		{
    			int h = height[index.top()];
    			index.pop();
    			int l = index.empty() ? -1: index.top();
    			result = max(result, h * (i - l - 1));
    		}
    	}
    	return result;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        int m, n;
    	if ((m = matrix.size()) == 0 || (n = matrix[0].size()) == 0)
    		return 0;
        vector<int> heights(n, 0);
    	int result = 0;
    	for (int i = 0; i < m; ++i)
    	{
    		for (int j = 0; j < n; ++j)
    		{
    			if (matrix[i][j] == '1')
    				heights[j]++;
    			else
    				heights[j] = 0;
    		}
    		result = max(result, largestRectangleArea(heights));
    	}
    	return result;
    }
};