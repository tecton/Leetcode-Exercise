class Solution {
public:
    int climbStairs(int n) {
        int result = 0, *steps = new int[n + 1];
        steps[1] = 1;
        steps[2] = 2;
        for (int i = 3; i <= n; ++i)
            steps[i] = steps[i - 1] + steps[i - 2];
        result = steps[n];
        delete []steps;
        return result;
    }
};