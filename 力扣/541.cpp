class Solution {
public:
    string reverseStr(string s, int k) {
        for (int start = 0; start < s.length(); start += 2 * k) {
        // 如果剩余字符少于 k 个，则将剩余字符全部反转
        if (start + k > s.length()) {
            std::reverse(s.begin() + start, s.end());
        } else {
            // 反转前 k 个字符
            std::reverse(s.begin() + start, s.begin() + start + k);
        }
    }
    return s;




    }
};