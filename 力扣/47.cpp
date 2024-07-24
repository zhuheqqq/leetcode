class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;
    
    void permuteUniqueHelper(vector<int>& nums){
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
             if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
                    continue;
             }
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                permuteUniqueHelper(nums);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        used = vector<bool>(nums.size(), false);
        permuteUniqueHelper(nums);
        return ans;
    }
};