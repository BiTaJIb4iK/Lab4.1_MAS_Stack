std::string decodeString(std::string str) {
    std::stack<int> nums;
    std::stack<std::string> strings;
    std::string current_str = "";
    int current_num = 0;

    for (const char& c : str) {
        //Calculate number of repeated part
        if (std::isdigit(c)) {
            current_num = current_num * 10 + (c - '0');
        }
        //push number to the stack
        else if (c == '[') {
            nums.push(current_num);
            current_num = 0;
            strings.push(current_str);
            current_str = "";
        }
        else if (c == ']') {
            int num = nums.top();
            nums.pop();
            std::string prev_str = strings.top();
            strings.pop();
            for (int i = 0; i < num; i++) {
                prev_str += current_str;
            }
            current_str = prev_str;
        }
        else {
            current_str += c;
        }
    }

    return current_str;
}