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
            vector<vector<int> > subResult = combination(candidates, i, target - candidates[i]);
            for (int j = 0; j < subResult.size(); ++j)
            {
                subResult[j].insert(subResult[j].begin(), candidates[i]);
                result.push_back(subResult[j]);
            }
        }
        return result;
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combination(candidates, 0, target);
    }
};