class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int cnt = 0;
        int remote = 0, end = 0;
        for(int i = 0; i < len - 1; i++){
            if(remote >= i){
                if(i + nums[i] > remote){
                    remote = i + nums[i];
                }
                if(i == end){
                    end = remote;
                    cnt++;
                }
            }
            
        }
        return cnt;
    }
};