class Solution {
public:
    int romanToInt(string s) {
        int Roman[256];
        Roman['I'] = 1;
        Roman['V'] = 5;
        Roman['X'] = 10;
        Roman['L'] = 50;
        Roman['C'] = 100;
        Roman['D'] = 500;
        Roman['M'] = 1000;
        
        int *number = new int[s.size()];
        for (int i = 0; i < s.size(); ++i)
            number[i] = Roman[s[i]];
        
        int result = 0;
        for (int i = 0; i < s.size() - 1; ++i)
            if (number[i] < number[i + 1])
                result -= number[i];
            else
                result += number[i];
        result += number[s.size() - 1];
        delete []number;
        return result;
    }
};