class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, vowel = 0;
        for(int i = 0; i < s.length(); i++) {
            //进入窗口
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowel++;
            }
            if(i < k - 1) {//窗口大小不足k
                continue;
            }
            //2.更新答案
            ans = max(ans, vowel);
            //3.离开窗口
            char out = s[i - k + 1];
            if(out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u') {
                vowel--;
            }
        }
        return ans;
    }
};