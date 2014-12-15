class Solution {
public:
    void swap(vector<int> &num, int i, int j)
    {
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
    void nextPermutation(vector<int> &num) {
        int i = (int)num.size() - 1, j;
        for (j = i - 1; j >= 0; --j)
        {
            if (num[j] < num[j + 1])
                break;
        }
        if (j >= 0)
        {
            while (i >= 0) {
                if (num[i] > num[j])
                {
                    swap(num, i, j);
                    break;
                }
                i--;
            }
        }
        reverse(num.begin() + j + 1, num.end());
    }
};