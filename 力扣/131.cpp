class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    bool isPalindrome(const string& s, int start, int end){
        for(int i = start, j = end; i < j; i++, j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }

    void partitionHelper(string s, int start){
        if(start >= s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = start; i < s.size(); i++){
            if(isPalindrome(s, start, i)){
                string str = s.substr(start, i - start + 1);
                path.push_back(str);
            }else {
                continue;
            }
            partitionHelper(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        partitionHelper(s, 0);
        return ans;
    }
};