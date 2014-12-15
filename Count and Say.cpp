class Solution {
public:
    string countAndSay(int n) {
        string s1 = "1", s2 = "";
        for (int i = 1; i < n; ++i)
        {
            s2 = "";
            int count = 0;
            char c = s1[0];
            for (int j = 0; j <= s1.size(); ++j)
            {
                if (j == s1.size() || s1[j] != c)
                {
					stringstream ss;
					ss << count;
                    s2 += ss.str();
                    s2 += c;
                    count = 1;
					c = s1[j];
                }
                else
                    count++;
            }
            s1 = s2;
        }
        return s1;
    }
};