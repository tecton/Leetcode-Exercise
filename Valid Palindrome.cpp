class Solution {
public:
    bool isPalindrome(string s) {
        string p = "";
        for (int i = 0; i < s.size(); ++i)
            if (isalpha(s[i]))
                p += tolower(s[i]);
            else if (isdigit(s[i]))
                p += s[i];
        for (int i = 0; i <= p.size() / 2; ++i)
            if (p[i] != p[p.size() - 1 - i])
                return false;
        return true;
    }
};