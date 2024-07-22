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

//优化之后版本排序+剪枝
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // 如果 sum + candidates[i] > target 就终止遍历
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();

        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end()); // 需要排序
        backtracking(candidates, target, 0, 0);
        return result;
    }
};