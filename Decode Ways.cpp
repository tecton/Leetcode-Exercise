class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0)
    		return 0;
    	vector<int> decode(s.size(), 0);
    	if (s[0] > '0' && s[0] <= '9')
    	    decode[0] = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            int one = 0, two = 0;
            if (s[i] > '0' && s[i] <= '9')
				one = 1;
            int num = atoi(s.substr(i - 1, 2).c_str());
            if (num > 9 && num < 27)
                two = 1;
            int last = i - 2 >= 0? decode[i - 2]: 1;
            decode[i] = one * decode[i - 1] + two * last;
        }
        return decode[s.size() - 1];
    }
};