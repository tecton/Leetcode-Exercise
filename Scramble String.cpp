class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
    		return false;
    	if (s1 == s2)
    		return true;
    	int l = s1.length();
    	string alpha1(s1), alpha2(s2);
    	sort(alpha1.begin(), alpha1.end());
    	sort(alpha2.begin(), alpha2.end());
    	if (alpha1 != alpha2)
    		return false;
    	for (int i = 1; i < l; ++i)
    	{
    		if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
    			return true;
    		if (isScramble(s1.substr(0, i), s2.substr(l - i)) && isScramble(s1.substr(i), s2.substr(0, l - i)))
    			return true;
    	}
    	return false;
    }
};