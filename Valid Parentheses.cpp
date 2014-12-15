class Solution {
public:
    bool isValid(string s) {
        if (s == "")
            return true;
        stack<char> pstack;
        pstack.push(s[0]);
        for (int i = 1; i < s.size(); ++i)
        {
			if (!pstack.empty())
			{
				char c = pstack.top();
				if ((c == '(' && s[i] == ')') || (c == ')' && s[i] == '('))
					pstack.pop();
				else if ((c == '{' && s[i] == '}') || (c == '}' && s[i] == '{'))
					pstack.pop();
				else if ((c == '[' && s[i] == ']') || (c == ']' && s[i] == '['))
					pstack.pop();
				else
					pstack.push(s[i]);
			}
			else
				pstack.push(s[i]);
        }
        return pstack.empty();
    }
};