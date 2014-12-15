class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        string s = a.size() > b.size() ? b: a;
        string l = a.size() > b.size() ? a: b;
        int carry = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int si = s[s.size() - 1 - i] - '0';
            int li = l[l.size() - 1 - i] - '0';
            int sum = si + li + carry;
            carry = sum / 2;
            result += ('0' + sum % 2);
        }
        for (int i = 0; i < l.size() - s.size(); ++i)
        {
            int sum = l[l.size() - s.size() - 1 - i] - '0' + carry;
            carry = sum / 2;
            result += ('0' + sum % 2);
        }
        if (carry == 1)
            result += '1';
        reverse(result.begin(), result.end());
        return result;
    }
};