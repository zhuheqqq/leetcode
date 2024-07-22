class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void combinationSumHelper(vector<int>& candidates, int target, int sum, int start){
        if(sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(path);
        }

        for(int i = start; i < candidates.size(); i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            combinationSumHelper(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combinationSumHelper(candidates, target, 0, 0);
        return ans;
    }
};