class Solution {
public:
    int work(vector<int>& nums, int k) {
        int len = 0;
        for(auto num : nums)
        {
            if(len < k || nums[len - k] != num){
                nums[len++] = num;
            }
        }
        return len;
    }
    int removeDuplicates(vector<int>& nums) {
        return work(nums, 2);

    }
};

/*删除有序数组重复项的通解
由于是保留 k 个相同数字，对于前 k 个数字，我们可以直接保留
对于后面的任意数字，能够保留的前提是：与当前写入的位置前面的第 k 个元素进行比较，不相同则保留
*/

