#include <iostream>
#include <string.h>
#include <vector>
#include <random>
#include <unordered_set>
#include <stack>

int longestValidParentheses(std::string s) {
    int maxLen = 0;
    std::stack<int> stack;
    stack.push(-1);  

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stack.push(i);  
        }
        else {
            stack.pop();  

            if (!stack.empty()) {
                maxLen = std::max(maxLen, i - stack.top());  
            }
            else {
                stack.push(i);  
            }
        }
    }

    return maxLen;
}

int main() {

    std::cout << longestValidParentheses("(()");

}
