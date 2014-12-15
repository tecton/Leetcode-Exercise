class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int newSize = n;
        for (int i = 0; i < newSize; ++i)
        {
            if (A[i] == elem)
            {
                A[i] = A[newSize - 1];
                newSize--;
                i--;
            }
        }
        return newSize;
    }
};