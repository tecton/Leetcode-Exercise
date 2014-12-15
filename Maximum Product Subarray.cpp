class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n <= 0)
            return 0;
        vector<int> maxProduct(n, 0);
        vector<int> minProduct(n, 0);
        maxProduct[0] = A[0];
        minProduct[0] = A[0];
        for (int i = 1; i < n; ++i)
        {
            maxProduct[i] = max(A[i], A[i] * maxProduct[i - 1]);
            maxProduct[i] = max(maxProduct[i], A[i] * minProduct[i - 1]);
            minProduct[i] = min(A[i], A[i] * minProduct[i - 1]);
            minProduct[i] = min(minProduct[i], A[i] * maxProduct[i - 1]);
        }
        return *max_element(maxProduct.begin(), maxProduct.end());
    }
};