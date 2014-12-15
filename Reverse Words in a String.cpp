class Solution {
public:
    void reverseWords(string &s) {
        istringstream iss(s);
    	string word = "", result = "";
    	while (iss >> word)
    	{
    		result = word + " " + result;
    	}
    	s = result.substr(0, result.length() - 1);
    }
};