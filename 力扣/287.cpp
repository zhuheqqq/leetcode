//哈希
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map <int, int> set;
        for(int num : nums){
            set[num]++;
            if(set[num] > 1){
                return num;
            }
        }

    return -1;
    }
};