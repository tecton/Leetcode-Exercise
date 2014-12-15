class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> consNum;
    	int result = 0;
    	for (int i = 0; i < num.size(); ++i)
    		consNum[num[i]] = 1;
    	for (unordered_map<int, int>::iterator iter = consNum.begin(); iter != consNum.end(); ++iter)
    	{
    		if (iter->second > 1)
    			continue;
    		unordered_map<int, int>::iterator cur = consNum.find(iter->first - 1);
    		while (cur != consNum.end())
    		{
    			iter->second++;
    			cur->second = 2;
    			cur = consNum.find(cur->first - 1);
    		}
    		cur = consNum.find(iter->first + 1);
    		while (cur != consNum.end())
    		{
    			iter->second++;
    			cur->second = 2;
    			cur = consNum.find(cur->first + 1);
    		}
    		result = max(result, iter->second);
    	}
    	return result;
    }
};