/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ssize=s.size();
        int pszie=p.size();
        vector<int> ans;
        vector<int> sresult(26);
        vector<int> presult(26);
        int i=0;

        if(ssize<pszie)
        {
            return vector<int>();
        }

        for(int k=0;k<pszie;k++)
        {
            presult[p[k]-'a']++;
            sresult[s[k]-'a']++;
            
        }
        if(presult==sresult)
        {
            ans.emplace_back(0);
        }

        for(int i=0;i<ssize-pszie;++i)
        {
            --sresult[s[i]-'a'];
            ++sresult[s[i+pszie]-'a'];
        

            if(sresult==presult)
            {
                ans.emplace_back(i+1);
            }

        }

        return ans;

    }
};
// @lc code=end

