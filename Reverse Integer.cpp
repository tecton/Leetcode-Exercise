class Solution {
public:
    int reverse(int x) {
        int reversedNumber = 0;
        if (x < 0)
            return -reverse(-x);
        while (x != 0)
        {
            reversedNumber = reversedNumber * 10 + x % 10;
            x = x / 10;
        }
        return reversedNumber;
    }
};