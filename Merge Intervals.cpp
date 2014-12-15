/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool intervalCmp(Interval a, Interval b)
{
	if (a.start != b.start)
		return a.start < b.start;
	return a.end < b.end;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2)
		    return intervals;
        sort(intervals.begin(), intervals.end(), intervalCmp);
    	int writer = 0, reader = 1;
    	while (reader < intervals.size())
    	{
    		if (intervals[reader].start <= intervals[writer].end)
    			intervals[writer].end = max(intervals[writer].end, intervals[reader].end);
    		else
    		{
    			writer++;
    			intervals[writer].start = intervals[reader].start;
    			intervals[writer].end = intervals[reader].end;
    		}
    		reader++;
    	}
    	intervals.erase(intervals.begin() + writer + 1, intervals.end());
    	return intervals;
    }
};