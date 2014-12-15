class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	map<int, int> hashmap;
    	vector<int> result(2, -1);
    	for (int i = 0; i < numbers.size(); ++i)
    	{
    		if (hashmap.find(target - numbers[i]) != hashmap.end())
    		{
    			int index = hashmap.find(target - numbers[i])->second;
    			if (index < i)
    			{
    				result[0] = index + 1;
    				result[1] = i + 1;
    				return result;
    			}
    			else if (index > i)
    			{
    				result[0] = i + 1;
    				result[i] = index + 1;
    				return result;
    			}
    		}
    		hashmap[numbers[i]] = i;
    	}
    	return result;
    }
};