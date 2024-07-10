class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int remote = 0;
        for(int i = 0; i < len; i++){
            if(remote >= i){
                if(i + nums[i] > remote){
                    remote = i + nums[i];
                }
                if(remote >= len - 1){
                    return true;
                }
            }
            
        }
        return false;
    }
};