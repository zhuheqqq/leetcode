class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int middle = left + (right - left) / 2;
            if(nums[middle] > nums[right]) {
                left = middle + 1;
            }else {
                right = middle;
            }
        }
        return nums[right];
    }
};