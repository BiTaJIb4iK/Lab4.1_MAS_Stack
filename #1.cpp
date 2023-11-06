#include <iostream>
#include <string.h>
#include <vector>
#include <random>
#include <unordered_set>
#include <stack>

char getOppositeBracket(char c) {
    switch (c)
    {
    case ')':
        return '(';
    case '}':
        return '{';
    case ']':
        return '[';
    default:
        throw 1;
    }

    return 0;
}

bool checkBracketsSyntax(std::string str) {
    std::stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        }
        else {
            if (s.top() == getOppositeBracket(str[i]))
                s.pop();
            else return false;
        }
    }

    return s.empty();
}


int main() {
    //std::cout << (int)'(' << ' ' << (int)')' << ' ' << (int)'{' << ' ' << (int)'}' << ' ' << (int)'[' << ' ' << (int)']' << '\n';
    //40 41 123 125 91 93

    std::cout << checkBracketsSyntax("()[{}");

}
