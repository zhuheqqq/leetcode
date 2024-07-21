class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void combinationSum3Helper(int k, int n, int sum, int start){
        if(path.size() == k && sum == n){
            ans.push_back(path);
            return;
        }

        for(int i = start; i < 9; i++){
            sum += i;
            path.push_back(i);
            combinationSum3Helper(k, n, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        combinationSum3Helper(k, n, 0, 1);
        return ans;
    }
};