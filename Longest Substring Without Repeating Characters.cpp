class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1)
            return s.length();
        bool hash[256];
        memset(hash, 0, sizeof(hash));
        int scanner, prober;
        int result = 1;
        for (scanner = 0; scanner < s.length(); ++scanner)
        {
            prober = scanner;
            while (prober < s.length())
            {
                if (hash[s[prober]])
                {
                    memset(hash, 0, sizeof(hash));
                    while (s[scanner] != s[prober])
						scanner++;
					break;
                }
                else
                {
                    hash[s[prober]] = true;
                    result = max(result, prober - scanner + 1);
					prober++;
                }
            }
        }
        return result;
    }
};