
class Solution {
public:
     vector<string> split(const string &s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    bool wordPattern(string pattern, string s) {
        vector<string> strings = split(s, ' ');

        if(pattern.length() != strings.size()) {
            return false;
        }

        unordered_map<char, string> map;
        unordered_map<string, char> reverse_map;

        for(int i = 0; i < strings.size(); i++) {
            char c = pattern[i];
            string word = strings[i];

            //没有映射关系则新建
            if(map.find(c) == map.end()) {
                if(reverse_map.find(word) != reverse_map.end()) {
                    return false;
                }
                map[c] = word;
                reverse_map[word] = c;
            }else {
                if(map[c] != word) {
                    return false;
                }
            }
        }
        return true;
    }
};