class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int writer = m + n - 1, readerA = m - 1, readerB = n - 1;
        while (writer > -1)
        {
            if  (readerA > -1 && readerB > -1)
                A[writer--] = (A[readerA] > B[readerB])? A[readerA--]: B[readerB--];
            else if (readerA > -1)
                A[writer--] = A[readerA--];
            else
                A[writer--] = B[readerB--];
        }
    }
};