//先计数排序，再统计大于k的论文数量

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> cnt(n + 1);
        for (int c : citations) {
            cnt[min(c, n)]++;
        }
        int s = 0;
        for (int i = n; ; i--){
            s += cnt[i];
            if (s >= i){
                return i;
            }
        }
    }
};