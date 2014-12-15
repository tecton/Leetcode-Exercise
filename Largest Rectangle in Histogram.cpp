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
};