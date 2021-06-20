class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for (const auto &charater : s) {
            if (charater == '(') {
                stack.push('(');
            } else if (charater == '[') {
                stack.push('[');
            } else if (charater == '{') {
                stack.push('{');
            } else if (charater == ')') {
                if (stack.size() == 0) {
                    return false;
                } else if (stack.top() != '(') {
                    return false;
                } else {
                    stack.pop();
                }
            } else if (charater == ']') {
                if (stack.size() == 0) {
                    return false;
                } else if (stack.top() != '[') {
                    return false;
                } else {
                    stack.pop();
                }
            }  else if (charater == '}') {
                if (stack.size() == 0) {
                    return false;
                } else if (stack.top() != '{') {
                    return false;
                } else {
                    stack.pop();
                }
            }
        }
        
        return (stack.size() == 0);
    }
};