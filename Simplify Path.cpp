class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        stack<string> simplified;
        while (path.find("/") != string::npos)
        {
            string dir = path.substr(0, path.find("/"));
            if (dir != "")
                dirs.push_back(dir);
            path = path.substr(path.find("/") + 1);
        }
        if (path != "")
            dirs.push_back(path);
        for (int i = 0; i < dirs.size(); ++i)
        {
            if (dirs[i] == ".." && !simplified.empty())
                simplified.pop();
            else if (dirs[i] != "." && dirs[i] != "..")
                simplified.push(dirs[i]);
        }
        string result = "";
        while (!simplified.empty())
        {
            result = "/" + simplified.top() + result;
            simplified.pop();
        }
        if (result == "")
            result = "/";
        return result;
    }
};