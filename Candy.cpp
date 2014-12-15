class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = (int)ratings.size();
        if (n < 2)
            return n;
        int result = 1;
        int lastCandies = 1, descNum = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i == n || ratings[i] >= ratings[i - 1])
            {
                if (descNum != 0)
                {
                    // add candies from 1 to descNum
                    result += (1 + descNum) * descNum / 2;
                    if (descNum + 1 > lastCandies)
                    {
                        // ratings [1, 2, 10, 5, 2, 1]
                        // candies [1, 2, 3] -> [1, 2, 4, 3, 2, 1]
                        result += descNum + 1 - lastCandies;
                    }
                    descNum = 0;
                    lastCandies = 1;
                }
                if (ratings[i] == ratings[i - 1])
                {
                    // could use 1 candy again
                    result += 1;
                    lastCandies = 1;
                }
                else if (i != n)
                    result += ++lastCandies;
            }
            else if (ratings[i] < ratings[i - 1])
            {
                descNum++;
            }
        }
        return result;
    }
};