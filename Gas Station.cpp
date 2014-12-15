class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            sum += gas[i] - cost[i];
        }
        if (sum < 0)
            return -1;
        int start = 0, step = 0;
        while (step < gas.size())
        {
            int iter = start;
            sum = 0;
            do
            {
                sum += gas[iter] - cost[iter];
                iter++;
                if (sum < 0)
                {
                    step += iter - start;
                    start = iter;
                    break;
                }
                if (iter == gas.size())
                    iter = 0;
				if (iter == start)
					return start;
            } while (iter != start);
        }
        return -1;
    }
};