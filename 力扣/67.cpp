class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int ca = 0;
        while(i >= 0 || j >= 0) {
            int sum = ca;
            if(i >= 0) {
                sum += a[i--] - '0';
            }
            if(j >= 0) {
                sum += b[j--] - '0';
            }
            ans += (sum % 2) + '0';
            ca = sum / 2;
        }
        if(ca == 1) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};