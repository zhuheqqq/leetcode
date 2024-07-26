class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return 1;
        }

        int direction = INT_MIN;
        int res = 0;

        for(int i = 1; i < len; i++) {
            if(nums[i] == nums[i - 1]){
                continue;
            }else if(nums[i] - nums[i - 1] > 0) {
                if(direction == 1){
                    continue;
                }
                direction = 1;
                res += 1;
            }else {
                if(direction == 0){
                    continue;
                }
                direction = 0;
                res += 1;
            }
        }
        return res + 1;

    }
};