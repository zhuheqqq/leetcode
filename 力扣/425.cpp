class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        if(intervals.size() ==0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0][1];
        int start = intervals[0][0];
        for(int i = 0; i < intervals.size() - 1; i++) {
            if(start == intervals[i + 1][0] || end > intervals[i + 1][0]){
                cnt++;
                if(end > intervals[i + 1][1]){
                    end = intervals[i + 1][1];
                    start = intervals[i + 1][0];
                }
            }else {
                start = intervals[i + 1][0];
                end = intervals[i + 1][1];
            }
        }
        return cnt;
    }
};