class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void subsetsWithDupHelper(vector<int>& nums, int start){
        ans.push_back(path);
        if(start >= nums.size()){
            
            return;
        }
        for(int i = start; i < nums.size(); i++){
            if (i > start && nums[i] == nums[i - 1] ) { // 注意这里使用i > startIndex
                continue;
            }
            path.push_back(nums[i]);
            subsetsWithDupHelper(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0){
            return ans;
        }
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(nums, 0);
        return ans;
    }
};