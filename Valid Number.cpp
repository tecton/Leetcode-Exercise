class Solution {
public:
    bool isNumber(const char *s) {
        string str(s);
    	int i = 0, digit = 0, dot = 0;
    	while (str[i] == ' ')
    		i++;
    	if (str[i] == '+' || str[i] == '-')
    		i++;
    	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
    		str[i++] == '.' ? dot++ : digit++;
    	if (dot > 1 || digit == 0)
    		return false;
    	if (str[i] == 'e')
    	{
    		i++;
    		if (str[i] == '+' || str[i] == '-')
    			i++;
    		int m = 0;
    		while (i < str.length())
    		{
    			if (str[i] >= '0' && str[i] <= '9')
    				m++;
    			else if (str[i] == ' ')
				    break;
    			else
    				return false;
    			i++;
    		}
    		if (m == 0)
    			return false;
    	}
    	while (str[i] == ' ')
    		i++;
    	return i == str.length();
    }
};