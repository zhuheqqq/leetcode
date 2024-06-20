//暴力解法，超出时间限制
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        for (int i = 0; i < temperatures.size(); i++) {
            for( int j = i; j < temperatures.size(); j++){
                if(temperatures[j] > temperatures[i]){
                    ans.push_back(j - i);
                    break;
                }else if(temperatures[j] <= temperatures[i] && j == temperatures.size() - 1){
                    ans.push_back(0);
                    break;
                }
                
            }
        }
        return ans;
    }
};

//单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int index = s.top();
                ans[index] = i - index;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};

