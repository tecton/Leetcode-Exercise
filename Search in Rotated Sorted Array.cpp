class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0, end = n - 1, middle;
        while (start <= end)
        {
            middle = (start + end) / 2;
            if (A[middle] == target)
                return middle;
            if (A[start] <= A[middle])
            {
                if (A[middle] > target && target >= A[start])
                    end = middle - 1;
                else
                    start = middle + 1;
            }
            else
            {
                if (target > A[middle] && target <= A[end])
                    start = middle + 1;
                else
                    end = middle - 1;
            }
        }
        return -1;
    }
};