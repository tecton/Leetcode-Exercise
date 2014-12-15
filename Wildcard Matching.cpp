class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *star = NULL, *lastS = NULL;
        while (*s)
        {
            if (*s == *p || *p == '?')
            {
                s++;
                p++;
                continue;
            }
            if (*p == '*')
            {
                star = p++;
                lastS = s;
                continue;
            }
            if (star != NULL)
            {
                p = star + 1;
                s = ++lastS;
                continue;
            }
            return false;
        }
        while (*p == '*')
            p++;
        return *p == '\0';
    }
};