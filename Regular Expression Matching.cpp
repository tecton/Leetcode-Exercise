class Solution {
public:
    bool singleMatch(const char *s, const char *p)
    {
    	return *p == *s || (*p == '.' && *s != '\0');
    }
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0')
    		return *s == '\0';
    	if (p[1] == '*')
    	{
    		if (isMatch(s, p + 2))
    			return true;
    		while (singleMatch(s, p))
    		{
    			if (isMatch(++s, p + 2))
    				return true;
    		}
    	}
    	else
    	{
    		if (!singleMatch(s, p))
    			return false;
    		return isMatch(s + 1, p + 1);
    	}
    	return false;
    }
};