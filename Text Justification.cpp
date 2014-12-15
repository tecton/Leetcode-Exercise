class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        vector<vector<int> > index;
        vector<int> curLine;
        int curSize = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            if (curSize == 0 || (curSize + words[i].length() + 1 <= L))
            {
                if (curSize != 0)
                    curSize++;
                curLine.push_back(i);
                curSize += words[i].length();
            }
            else if (curLine.size() > 0)
            {
                index.push_back(curLine);
                curLine.clear();
                curSize = 0;
                i--;
            }
        }
        if (curLine.size() > 0)
            index.push_back(curLine);
        for ( int i = 0; i < index.size() - 1; ++i)
        {
            string line = "";
            curLine = index[i];
            int spaceNum = L, slot = curLine.size();
            if (slot > 1)
                slot--;
            else
                slot = 0;
            for ( int j = 0; j < curLine.size(); ++j)
                spaceNum -= words[curLine[j]].length();
            int space;
            for ( int j = curLine.size() - 1; j >= 0; --j)
            {
                line = words[curLine[j]] + line;
                if (slot > 0)
                {
                    space = spaceNum / slot;
                    line = string(space, ' ') + line;
                    slot--;
                    spaceNum -= space;
                }
            }
            if (line.length() < L)
                line += string( L - line.length(), ' ');
            result.push_back(line);
        }
        curLine = index.back();
        string line = "";
        for ( int i = 0; i < curLine.size(); ++i)
        {
            line += words[curLine[i]] + ' ';
        }
        line = line.substr(0, line.length() - 1);
        if (line.length() < L)
            line += string( L - line.length(), ' ');
        result.push_back(line);
        return result;
    }
};