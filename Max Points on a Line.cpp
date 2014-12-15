/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() < 2)
        	return points.size();
    	int result = 0;
    	for (int i = 0; i < points.size(); ++i)
    	{
    		unordered_map<string, int> lines;
    		int overlap = 0, local = 0;
    		for (int j = i + 1; j < points.size(); ++j)
    		{
    			float k = (int)INT_MAX;
    			int deltaX = points[i].x - points[j].x;
    			int deltaY = points[i].y - points[j].y;
    			if (deltaX == 0 && deltaY == 0)
    			{
    				overlap++;
    				continue;
    			}
    			else if (deltaY == 0)
    				k = 0;
    			else if (deltaX != 0)
    				k = (float)(deltaY) / deltaX;
    			string line = to_string(k);
    			lines[line]++;
    			local = max(local, lines[line]);
    		}
    		result = max(result, local + overlap + 1);
    	}
    	return result;
    }
};