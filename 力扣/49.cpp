//将一组异位词重新排序之后作为他们的键，一组异位词作为该键的值

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string& str : strs)
        {
            string key = str;
            sort(key.begin(),key.end());
            mp[key].emplace_back(str);

        }

        vector<vector<string>> ans;
        for (auto it = mp.begin();it !=mp.end();++it) {
            ans.emplace_back(it->second);//it是迭代器，it->second代表取出其中值的部分
        }

        return ans;

    }
};