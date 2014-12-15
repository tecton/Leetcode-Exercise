class Solution {
public:
    void swap(int A[], int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    
    void sortColors(int A[], int n) {
        int red = 0, blue = n - 1;
		while (A[red] == 0)
			red++;
		while (A[blue] == 2)
			blue--;
        for (int i = red; i <= blue; ++i)
        {
            if (A[i] == 0)
            {
				if (i != red)
					swap(A, i--, red);
                while (red <= i && A[red] == 0)
                    red++;
            }
            else if (A[i] == 2)
            {
				if (i != blue)
					swap(A, i--, blue);
                while (blue >= i && A[blue] == 2)
                    blue--;
            }
        }
    }
};