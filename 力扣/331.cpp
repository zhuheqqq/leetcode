//用栈模拟 当有两个连续的#将连续的#全部出栈 再将栈顶元素出栈后填充一个# 
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return false;

        stack<string> Q;
        string num; // 用于存储多位数字

        for (char c : preorder) {
            if (c == ',') {
                if (!num.empty()) {
                    Q.push(num);
                    num.clear();
                }
            } else if (c == '#') {
                // 如果当前是'#'，则尝试弹出栈顶的两个'#'和一个数字
                while (!Q.empty() && Q.top() == "#") {
                    Q.pop(); // 弹出一个'#'
                    if (Q.empty() || Q.top() == "#") return false; // 弹出数字，如果栈空或栈顶仍为'#'，则非法
                    Q.pop(); // 弹出数字
                }
                Q.push("#"); // 将当前的'#'推入栈中
            } else {
                // 如果是数字的一部分，添加到num字符串
                num.push_back(c);
            }
        }

        // 处理最后一个节点（如果是数字的话）
        if (!num.empty()) {
            Q.push(num);
        }

        // 检查最终的栈状态
        return Q.size() == 1 && Q.top() == "#";
    }
};