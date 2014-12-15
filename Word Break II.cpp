class Solution {
public:
    void search(vector<string> &result, string sentence, string &s, vector<vector<int> > &nextIndex, int index, int n, vector<bool> &flag)
    {
    	if (index == n)
    	{
    		result.push_back(sentence.substr(0, sentence.length() - 1));
    		return;
    	}
    	bool reachEnd = false;
    	for (int i = 0; i < nextIndex[index].size(); ++i)
    	{
    		int end = nextIndex[index][i];
    		if (flag[end])
    		{
    			search(result, sentence + s.substr(index, end - index) + " ", s, nextIndex, end, n, flag);
    			reachEnd = true;
    		}
    	}
    	if (!reachEnd)
    		flag[index] = false;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
    	vector<vector<int> > nextIndex(n);
    	for (int i = n - 1; i >= 0; --i)
    	{
    		for (int j = i; j >= 0; --j)
    		{
    			if (dict.count(s.substr(j, i - j + 1)))
    				nextIndex[j].push_back(i + 1);
    		}
    	}
    	vector<string> result;
    	string sentence = "";
    	vector<bool> flag(n + 1, true);
    	search(result, sentence, s, nextIndex, 0, n, flag);
    	return result;
    }
};