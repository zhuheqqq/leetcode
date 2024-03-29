class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(const int &num : nums){
            num_set.insert(num);
        }

        int longestStreak = 0;
        for (const int& num : num_set){
            if(!num_set.count(num-1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum+1)) {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
            
        }
        return longestStreak;    

    }
};

//先利用set进行去重，然后利用哈希表判断本数的前一个数在不在哈希表中