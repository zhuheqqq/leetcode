class Solution {
public:
    vector<string> ans;

    bool isVaild(const string& s, int start, int end){
        if(start > end){
            return false;
        }
        if(s[start] == '0' && start != end){
            return false;
        }
        int num = 0;
        for(int i = start; i <= end; i++){
            if(s[i] > '9' || s[i] < '0'){
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if(num > 255){
                return false;
            }
        }
        return true;
    }

    void restoreIpAddressesHelper(string& s, int start, int pointNum){
        if(pointNum == 3){
            if(isVaild(s, start, s.size() - 1)){
                ans.push_back(s);
            }
            return;
        }
        for(int i = start; i < s.size(); i++){
            if(isVaild(s, start, i)){
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                restoreIpAddressesHelper(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            }else{
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12){
            return ans;
        }
        restoreIpAddressesHelper(s, 0, 0);
        return ans;
    }
};