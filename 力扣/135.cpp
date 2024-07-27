//先从左向右遍历再从右向左遍历
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);

        //从左向右
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1]){
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }
    //从右向左
        for(int i = ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        int result = 0;
        for(int i = 0; i < candyVec.size(); i++){
            result += candyVec[i];
        }

        return result;
    }
};

//贪心：一次是从左到右遍历，只比较右边孩子评分比左边大的情况。
//一次是从右到左遍历，只比较左边孩子评分比右边大的情况。