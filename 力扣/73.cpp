//下面是我自己写的shi
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> h,l;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    h.push_back(i);
                    l.push_back(j);
                }
            }
        }

        for(int i = 0; i < h.size(); i++){
            for(int j = 0; j < n; j++){
                matrix[h[i]][j] = 0;
            }
        }

        for(int i = 0; i < l.size(); i++){
            for(int j = 0; j < m; j++){
                matrix[j][l[i]] = 0;
            }
        }
    }
};