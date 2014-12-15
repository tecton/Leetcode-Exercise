class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int start = 0, end = n - 1, current;
        while (start <= end)
        {
            current = (start + end) / 2;
            if (A[current] == target)
                return current;
            else if (A[current] > target)
            {
                end = current - 1;
            }
            else
            {
                start = current + 1;
            }
        }
        return start;
    }
};