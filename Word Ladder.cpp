class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
            return 0;
        queue<pair<string, int> > q;
        q.push(make_pair(start, 1));
        int len = (int)start.length();
        while (!q.empty())
        {
            pair<string, int> curPair = q.front();
            string cur = curPair.first;
            q.pop();
            for (int i = 0; i < len; ++i)
            {
                char origin = cur[i];
                for (char c = 'a'; c <= 'z'; ++c)
                    if (c != origin)
                    {
                        cur[i] = c;
                        if (dict.find(cur)!= dict.end())
                        {
                            if (cur == end)
                                return curPair.second + 1;
                            else
                                q.push(make_pair(cur, curPair.second + 1));
                            dict.erase(cur);
                        }
                    }
                cur[i] = origin;
            }
        }
        return 0;
    }
};