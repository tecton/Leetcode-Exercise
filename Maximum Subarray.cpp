class Solution {
public:
    int maxSubArray(int A[], int n) {
        int *sum = new int[n];
        sum[0] = A[0];
        int result = A[0];
        for (int i = 1; i < n; ++i)
        {
            sum[i] = max(A[i], sum[i - 1] + A[i]);
            result = max(result, sum[i]);
        }
        return result;
    }
};