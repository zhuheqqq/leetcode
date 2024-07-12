class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++){
            int r = i + 1, l = numbers.size() - 1;
            while(r <= l){
                int m = (l - r) / 2 + r;
                if(numbers[m] == target - numbers[i]){
                    return {i + 1, m + 1};
                }else if(numbers[m] > target - numbers[i]){
                    l = m - 1;
                }else{
                    r = m + 1;
                }
            }
        }
        return {-1, -1};

    }
};