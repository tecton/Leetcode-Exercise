class Solution {
public:
    void permuteNum(vector<vector<int> > &result, vector<int> &cur, vector<bool> &mask, vector<int> &num)
    {
        if (cur.size() == num.size())
            result.push_back(cur);
        else
        {
            for (int i = 0; i < mask.size(); ++i)
            {
                if (!mask[i])
                {
                    cur.push_back(num[i]);
                    mask[i] = true;
                    permuteNum(result, cur, mask, num);
                    mask[i] = false;
                    cur.pop_back();
                }
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<bool> mask(num.size(), false);
        vector<vector<int> >result;
        vector<int> cur;
        permuteNum(result, cur, mask, num);
        return result;
    }
};