class Solution {
public:
    int search(int A[], int n, int target, bool lower)
    {
        int l = 0, r = n - 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (A[m] == target)
            {
                if (lower)
                    r = m;
                else
                {
                    if (l == m)
                        return A[r] == target? r: m;
                    l = m;
                }
            }
            else if (A[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return A[l] == target? l: -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2, -1);
        if (n == 0)
            return result;
        result[0] = search(A, n, target, true);
        result[1] = search(A, n, target, false);
        return result;
    }
};