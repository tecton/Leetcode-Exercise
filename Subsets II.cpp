class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> >result;
		result.push_back(vector<int>());
        sort(S.begin(), S.end());
        int startPos = 0, endPos = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            startPos = 0;
			if (i > 0 && S[i] == S[i - 1])
				startPos = endPos;
            endPos = result.size();
            for (int j = startPos; j < endPos; ++j)
            {
                vector<int> subset = result[j];
                subset.push_back(S[i]);
                result.push_back(subset);
            }
        }
        return result;
    }
};