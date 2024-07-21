class Solution {
public:
    vector<string> ans;
    string s;
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };

    void letterCombinationsHelper(const string& digits, int start){
        if(start == digits.size()){
            ans.push_back(s);
            return;
        }
        int digit = digits[start] - '0';
        string letter = letterMap[digit];
        for(int i = 0; i < letter.size(); i++){
            s.push_back(letter[i]);
            letterCombinationsHelper(digits, start + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return ans;
        }
        letterCombinationsHelper(digits, 0);
        return ans;
    }
};