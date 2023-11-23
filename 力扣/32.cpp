class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;  // 用于存储括号字符的索引
        int max_length = 0;  // 最长有效括号子串的长度
        int last_invalid = -1;  // 上一个无法匹配的')'的索引

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {  // 当前字符为')'
                if (!stk.empty()) {
                    stk.pop();  // 弹出与当前')'匹配的'('的索引
                    if (!stk.empty()) {
                        max_length = max(max_length, i - stk.top());  // 计算当前子串长度
                    } else {
                        max_length = max(max_length, i - last_invalid);  // 计算当前子串长度
                    }
                } else {
                    last_invalid = i;  // 当前')'无法匹配，更新last_invalid索引
                }
            }
        }

    return max_length;

    }
};