class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int result = num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); ++i)
        {
            int start = i + 1, end = num.size() - 1;
            while (start < end)
            {
                int sum = num[i] + num[start] + num[end];
                if (sum == target)
                    return sum;
                if (abs(sum - target) < abs(result - target))
                    result = sum;
                (sum > target)? end--: start++;
            }
        }
        return result;
    }
};