class Solution {
public:
    void permute(vector<vector<int> > &result, vector<int> &cur, vector<bool> &mask, vector<int> &num)
    {
        if (cur.size() == num.size())
            result.push_back(cur);
        else
        {
			int lastUsed = num[0] - 1;
            for (int i = 0; i < mask.size(); ++i)
            {
                if (!mask[i] && num[i] != lastUsed)
                {
                    cur.push_back(num[i]);
                    mask[i] = true;
                    permute(result, cur, mask, num);
                    mask[i] = false;
                    cur.pop_back();
					lastUsed = num[i];
                }
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<bool> mask(num.size(), false);
        vector<vector<int> >result;
        vector<int> cur;
		sort(num.begin(), num.end());
        permute(result, cur, mask, num);
        return result;
    }
};