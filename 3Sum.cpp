class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int i = 0;
        while (i < num.size())
        {
            int target = -num[i];
            int start = i + 1, end = num.size() - 1;
            while (start < end)
            {
                if (num[start] + num[end] < target)
                {
                    start++;
                }
                else if (num[start] + num[end] > target)
                {
                    end--;
                }
                else
                {
                    vector<int> triple;
                    triple.push_back(-target);
                    triple.push_back(num[start]);
                    triple.push_back(num[end]);
                    result.push_back(triple);
                    do
                    {
					    start++;
                    }
                    while (start < end && num[start] == num[start - 1]);
					do
                    {
                        end--;
                    }
                    while (end > start && num[end] == num[end + 1]);
                }
            }
            do
            {i++;}
            while (i < num.size() && num[i] == num[i - 1]);
        }
        return result;
    }
};