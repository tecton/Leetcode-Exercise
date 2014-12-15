class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL)
            return 0;
        int len = strlen(str);
        long long result = 0;
        bool negative = false;
        int i = 0;
        while (str[i] == ' ')
            i++;
        if (str[i] == '-')
        {
            negative = true;
            i++;
        }
        else if (str[i] == '+')
        {
            negative = false;
            i++;
        }
        for (; i < len; ++i)
        {
            if (!isdigit(str[i]))
                break;
            result = 10 * result + str[i] - '0';
        }
		result = negative ? -result: result;
		if (result > INT_MAX)
			return INT_MAX;
		if (result < INT_MIN)
			return INT_MIN;
        return (int)result;
    }
};