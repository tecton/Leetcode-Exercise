class Solution {
public:
    void addParenthesis(vector<string> &result, string cur, int leftP, int rightP)
    {
        if (leftP == 0 && rightP == 0)
            result.push_back(cur);
        else
        {
            if (leftP > 0)
                addParenthesis(result, cur + "(", leftP - 1, rightP);
            if (rightP > leftP)
                addParenthesis(result, cur + ")", leftP, rightP - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addParenthesis(result, "", n, n);
        return result;
    }
};