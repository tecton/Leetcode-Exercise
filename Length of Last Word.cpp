class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = strlen(s);
        int start = -1;
        for (int i = length - 1; i > -1; --i)
        {
            if (isalpha(s[i]))
            {
                if (start == -1)
                    start = i;
            }
            else if (s[i] == ' ')
            {
                if (start != -1)
                    return start - i;
            }
        }
        if (start != -1)
            return start + 1;
        return 0;
    }
};