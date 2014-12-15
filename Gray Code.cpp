class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for (int i = 0; i < pow(2, n); ++i)
        {
            int num = i ^ (i >> 1);
            result.push_back(num);
        }
        return result;
    }
};