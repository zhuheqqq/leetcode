class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void findSubsequencesHelper(vector<int>& nums, int start){
        if(path.size() >= 2){
            ans.push_back(path);
        }
        unordered_set<int> uset; // 使用set对本层元素进行去重
        for (int i = start; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back())
                    || uset.find(nums[i]) != uset.end()) {
                    continue;
            }
            uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
            path.push_back(nums[i]);
            findSubsequencesHelper(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size() == 0) {
            return ans;
        }
        findSubsequencesHelper(nums, 0);
        return ans;
    }
};