/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
    	int reader = 0, writer = 0;
    	bool inserted = false;
    	if (intervals.size() < 1)
    	{
    		result.push_back(newInterval);
    		return result;
    	}
    	if (intervals[0].start < newInterval.start)
    	{
    		result.push_back(intervals[0]);
    	}
    	else
    	{
    		result.push_back(newInterval);
    		inserted = true;
    	}
    	while (reader < intervals.size())
    	{
    		if (!inserted)
    		{
    			if (newInterval.start <= result[writer].end)
    			{
    				result[writer].end = max(result[writer].end, newInterval.end);
    				inserted = true;
    			}
    			else if (newInterval.start < intervals[reader].start)
    			{
    				result.push_back(newInterval);
    				writer++;
    				inserted = true;
    			}
    		}
    		if (intervals[reader].start <= result[writer].end)
    		{
    			result[writer].end = max(result[writer].end, intervals[reader].end);
    		}
    		else
    		{
    			result.push_back(intervals[reader]);
    			writer++;
    		}
    		reader++;
    	}
    	if (!inserted)
    	{
    		if (newInterval.start <= result[writer].end)
    			result[writer].end = max(result[writer].end, newInterval.end);
    		else
    			result.push_back(newInterval);
    	}
    	return result;
    }
};