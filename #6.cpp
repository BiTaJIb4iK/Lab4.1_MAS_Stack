class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;

        for (const std::string& token : tokens) {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                stack.push(std::stoi(token));
            } else {
                int operand2 = stack.top();
                stack.pop();
                int operand1 = stack.top();
                stack.pop();
                if (token == "+") {
                    stack.push(operand1 + operand2);
                } else if (token == "-") {
                    stack.push(operand1 - operand2);
                } else if (token == "*") {
                    stack.push(operand1 * operand2);
                } else if (token == "/") {
                    stack.push(operand1 / operand2);
                }
            }
        }
        
        return stack.top();
    }
};