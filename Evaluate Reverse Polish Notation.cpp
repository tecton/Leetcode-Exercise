class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (!(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"))
                nums.push(atoi(tokens[i].c_str()));
            else
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                switch (tokens[i][0])
                {
                    case '+':
                        nums.push(num1 + num2);
                        break;
                    case '-':
                        nums.push(num2 - num1);
                        break;
                    case '*':
                        nums.push(num1 * num2);
                        break;
                    case '/':
                        nums.push(num2 / num1);
                        break;
                }
            }
        }
        return nums.top();
    }
};