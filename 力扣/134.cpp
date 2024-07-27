class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cursum  = 0;
        int totalsum = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++) {
            cursum += gas[i] - cost[i];
            totalsum += gas[i] -cost[i];
            if(cursum < 0) {
                start = i + 1;
                cursum = 0;
            }
        }
        if(totalsum < 0) {
            return -1;
        }
        return start;
    }
};