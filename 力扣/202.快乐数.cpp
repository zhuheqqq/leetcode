/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int getnum(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=(n%10)*(n%10);
            n/=10;
        }

        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;

        while(1)
        {
            int num=getnum(n);

            if(num==1)
            {
                return true;
            }

            if(set.find(num)!=set.end())
            {
                return false;
            }else{
                set.insert(num);
            }

            n=num;
        }

    }
};
// @lc code=end

