class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void combinationSum2Helper(vector<int>& candidates, int target, int sum, int start){
        if(sum == target){
            ans.push_back(path);
            return;
        }
        for(int i = start; i < candidates.size() && sum + candidates[i] <= target; i++){
            if(i > start && candidates[i] == candidates[i - 1]){
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            combinationSum2Helper(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combinationSum2Helper(candidates, target, 0, 0);
        return ans;
    }
};