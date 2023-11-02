/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int hash[1005]={0};
        for(int num:nums1)
        {
            hash[num]++;
        }

        for(int num:nums2)
        {
            if(hash[num]!=0)
            {
                result.push_back(num);
                hash[num]--;
            }
        }

        return result;

    }
};
// @lc code=end

