//排序，但是题目中没有说明多数元素只存在一个
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        return nums[size/2];

    }
};

//摩尔投票算法，思想很巧妙
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 0,votes = 0;
        for (int num : nums) {
            if(votes == 0) {
                x = num;
            }
            votes += num == x ? 1 : -1;
        }
        return x;
    }
};