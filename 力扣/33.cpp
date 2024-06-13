class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while(left <= right) {
            int middle = (left + right) / 2;
            if(nums[left] > nums[right]) {
                //数组无序
                if(nums[middle] < nums[right]) {
                    //middle到right部分有序
                    if(target >= nums[middle] && target <= nums[right]) {
                        left = middle;
                    }else {
                        right = middle - 1;
                    }
                }else {
                    //left到middle部分有序
                    if(target >= nums[left] && target <= nums[middle]) {
                        right = middle;
                    }else {
                        left = middle + 1;
                    }
                }
            }else {
                //数组有序
                if(target > nums[right]){
                    return -1;
                }else if(target < nums[left])
                {
                    return -1;
                }else {
                    if(nums[middle] == target){
                        return middle;
                    }else if(nums[middle] > target){
                        right = middle - 1;
                    }else {
                        left = middle + 1;
                    }
                }
            }
        }
        return -1;

    }
};

//简化版
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int middle = left + (right - left) / 2;
            
            if (nums[middle] == target) {
                return middle;
            }
            
            // 判断左半部分是否有序
            if (nums[left] <= nums[middle]) {
                if (nums[left] <= target && target < nums[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } 
            // 右半部分一定有序
            else {
                if (nums[middle] < target && target <= nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }
        
        return -1;
    }
};

