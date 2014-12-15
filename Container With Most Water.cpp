class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        if (n < 2)
            return 0;
        int low = 0, high = n - 1;
        int result = 0;
        while(low != high)
        {
            result = max(result, (high - low) * min(height[low], height[high]));
            if (height[low] > height[high])
                high--;
            else
                low++;
        }
        return result;
    }
};