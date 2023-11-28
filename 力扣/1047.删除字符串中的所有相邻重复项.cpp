/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> x_stack;

        for(char c:s)
        {
            if(!x_stack.empty())
            {
                if(x_stack.top()==c)
                {
                    x_stack.pop();
                }else{
                    x_stack.push(c);
                }
            }else{
                x_stack.push(c);
            }
        }

        string result = "";
        while (!x_stack.empty()) { // 将栈中元素放到result字符串汇总
            result += x_stack.top();
            x_stack.pop();
        }
        reverse (result.begin(), result.end()); // 此时字符串需要反转一下
        return result;

    }
};
// @lc code=end

