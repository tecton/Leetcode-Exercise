class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 0, sum;
        vector<int> result;
        digits[digits.size() - 1] += 1;
        for (int i = digits.size() - 1; i >= 0 ; --i)
        {
            sum = digits[i] + carry;
            result.insert(result.begin(), sum % 10);
            carry = sum / 10;
        }
        if (carry)
            result.insert(result.begin(), carry);
        return result;
    }
};