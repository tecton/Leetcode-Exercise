class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((long long)dividend);
	    long long b = abs((long long)divisor);
    	long long result = 0;
    	while (a >= b)
    	{
    		long long m = 1, d = b;
    		while ((d << 1) <= a)
    		{
    			d <<= 1;
    			m <<= 1;
    		}
    		result += m;
    		a -= d;
    	}
    	if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
    		return (int)-result;
    	else
    		return (int)result;
    }
};