//只需要判断哈希表的值是否相同就可以不用管键
//不对，顺序也需要注意
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int len = s.size();
        if(len != t.size()){
            return false;
        }
        for(int i = 0; i < len; i++){
            char x = s[i], y = t[i];
            if((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)){
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};