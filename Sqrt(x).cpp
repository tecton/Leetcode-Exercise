class Solution {
public:
    int sqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int hi = x, lo = 1;
        int result;
        while (lo <= hi)
        {
            int m = (hi + lo) / 2;
            if (m > x / m)
                hi = m - 1;
            else if (m < x / m)
            {
                lo = m + 1;
                result = m;
            }
            else
                return m;
        }
        return result;
    }
};