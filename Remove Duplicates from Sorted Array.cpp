class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 1)
            return 1;
        int reader = 0, writer = 0;
        while (reader < n)
        {
            if (reader + 1 < n && A[reader] == A[reader + 1])
                reader++;
            else
                A[writer++] = A[reader++];
        }
        if (reader < n && reader - 1 > -1 && A[reader] != A[reader - 1])
            A[writer++] = A[reader];
        return writer;
    }
};