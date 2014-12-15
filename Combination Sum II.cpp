class Solution {
public:
    vector<vector<int> > combination(vector<int> &candidates, int start, int target)
    {
        vector<vector<int> > result;
		if (0 == target)
		{
			vector<int> empty;
            result.push_back(empty);
			return result;
		}
		if (start >= candidates.size() || candidates[start] > target)
            return result;
        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i)
        {
            vector<vector<int> > subResult = combination(candidates, i + 1, target - candidates[i]);
            for (int j = 0; j < subResult.size(); ++j)
            {
                subResult[j].insert(subResult[j].begin(), candidates[i]);
                result.push_back(subResult[j]);
            }
			while (i + 1 < candidates.size() && candidates[i + 1] ==  candidates[i])
				i++;
        }
        return result;
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        return combination(num, 0, target);
    }
};