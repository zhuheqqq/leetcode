class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size();i++)
        {
            while(i<intervals.size()-1&&intervals[i+1][0]<=intervals[i][1])
            {
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1],intervals[i+1][1]);
                i++;
            }
            res.push_back(intervals[i]);
        }
        return res;
    }
};