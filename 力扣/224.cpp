class Solution {
public:
    int calculate(string s) {
        stack<int> operandStack;
        stack<int> signStack; // 用于处理括号前的正负号
        int result = 0;
        int num = 0;
        int sign = 1; // 1表示正号，-1表示负号

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                operandStack.push(result);
                signStack.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= signStack.top(); // 弹出括号前的正负号
                signStack.pop();
                result += operandStack.top(); // 弹出括号前的结果
                operandStack.pop();
            }
        }

        // 处理最后一个数字
        result += sign * num;

        return result;
    }
};
