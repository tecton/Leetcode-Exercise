class Solution {
public:
    string multiply(string num, int d)
    {
        string result = "";
        int carry = 0;
        for (int i = 0; i < num.size(); ++i)
        {
            int m = (num[i] - '0') * d + carry;
            result += '0' + m % 10;
            carry = m / 10;
        }
        if (carry)
            result += '0' + carry;
        return result;
    }
    string add(string num1, string num2)
    {
        string result = "";
        int carry = 0;
        int len = max(num1.size(), num2.size());
        for (int i = 0; i < len; ++i)
        {
            int sum = carry;
            if (i < num1.size())
                sum += num1[i] - '0';
            if (i < num2.size())
                sum += num2[i] - '0';
            result += '0' + sum % 10;
            carry = sum / 10;
        }
        if (carry)
            result += '0' + carry;
        return result;
    }
    string multiply(string num1, string num2) {
        string result = "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num2.size(); ++i)
        {
            string tempResult = multiply(num1, num2[i] - '0');
            for (int j = 0; j < i; ++j)
                tempResult.insert(tempResult.begin(), '0');
            result = add(result, tempResult);
        }
        reverse(result.begin(), result.end());
        while (result.size() > 1 && result[0] == '0')
            result = result.substr(1);
        return result;
    }
};