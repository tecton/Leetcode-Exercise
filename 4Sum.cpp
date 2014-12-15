class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int i = 0;
        while (i < num.size())
        {
            int j = num.size() - 1;
            while (j > i)
            {
                int sum = target -num[i] - num[j];
                int start = i + 1, end = j - 1;
                while (start < end)
                {
                    if (num[start] + num[end] < sum)
                    {
                        start++;
                    }
                    else if (num[start] + num[end] > sum)
                    {
                        end--;
                    }
                    else
                    {
                        vector<int> triple;
                        triple.push_back(num[i]);
                        triple.push_back(num[start]);
                        triple.push_back(num[end]);
                        triple.push_back(num[j]);
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
                {j--;}
                while (j > i && num[j] == num[j + 1]);
            }
            do
            {i++;}
            while (i < num.size() && num[i] == num[i - 1]);
        }
        return result;
    }
};