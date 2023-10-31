/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x>=0)
        {
            long long sum=0,k=x;
            while(k)
            {
                long i=k%10;
                sum=sum*10+i;
                k/=10;
            }
            if(sum==x)
            {
                return true;
            }else{
                return false;
            }

        }else{
            return false;
        }
        
    }
};
// @lc code=end

