
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dictionary;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int num = nums[i];
            if(dictionary.count(num) && i - dictionary[num] <= k){
                return true;
            }
            dictionary[num] = i;
        }
        return false;
    }
};