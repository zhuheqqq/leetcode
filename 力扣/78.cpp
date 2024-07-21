class Solution {
public:
    vector<int> set;
    void subsetsHelper(vector<int>& nums, int start,vector<vector<int>>& ans){
        ans.push_back(set);
        if (start >= nums.size()){
            return ;
        }

        for(int i = start; i < nums.size(); i++){
            set.push_back(nums[i]);
            subsetsHelper(nums, i + 1, ans);
            set.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        subsetsHelper(nums, 0, ans);
        return ans;
    }
};