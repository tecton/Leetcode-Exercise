class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int lenn = strlen(needle), lenh = strlen(haystack);
        int i = 0, j = 0;
        if (!haystack || lenn > lenh)
            return NULL;
        while (i <= lenh - lenn)
        {
            bool match = true;
            for (j = 0; j < lenn; ++j)
                if (haystack[i + j] != needle[j])
                {
                    match = false;
                    break;
                }
            if (match)
                return &haystack[i];
            i++;
        }
        return NULL;
    }
};