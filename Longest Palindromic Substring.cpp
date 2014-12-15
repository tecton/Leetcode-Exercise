class Solution {
public:
    string findPalindrome(string s, int start, int end)
    {
        while (start >= 0 && end < s.length())
        {
            if (s[start] == s[end])
            {
                start--;
                end++;
            }
            else
                break;
        }
        return s.substr(start + 1, end - start - 1);
    }
    string longestPalindrome(string s) {
        string longest = "";
        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                string sub = findPalindrome(s, i, i + j);
                if (sub.length() > longest.length())
                    longest = sub;
            }
        }
        return longest;
    }
};