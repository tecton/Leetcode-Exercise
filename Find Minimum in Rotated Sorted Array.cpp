class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        if (n == 1)
            return num[0];
        for (int i = 1; i < num.size(); ++i)
            if (num[i] < num[i - 1])
                return num[i];
        return num[0];
    }
};