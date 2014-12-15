class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > mp;
        vector<string> result;
        for (int i = 0; i < strs.size(); ++i)
        {
			string str = strs[i];
			sort(str.begin(), str.end());
            mp[str].push_back(strs[i]);
        }
		map<string, vector<string> >::iterator iter;
		for (iter = mp.begin(); iter != mp.end(); ++iter)
		{
			if (iter->second.size() > 1)
				result.insert(result.end(), iter->second.begin(), iter->second.end());
		}
		return result;
    }
};