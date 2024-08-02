class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);  // 初始化答案数组为-1
        stack<int> st;           // 存储数组元素的索引
        
        // 遍历数组两次以处理循环
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i % n]) {
                ans[st.top()] = nums[i % n];
                st.pop();
            }
            if (i < n) {
                st.push(i);
            }
        }
        
        return ans;
    }
};