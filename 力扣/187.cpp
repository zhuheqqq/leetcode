class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int len=s.size();

        if(len<10)
        {
            return ans;
        }

        int i=0;
        unordered_set<string> hash,add_to_ans;
        for(i=0;i<=len-10;i++)
        {
            //cout<<i<<endl;
            string sv(s.data()+i,10);
            if (hash.contains(sv)) {
                if (add_to_ans.insert(sv).second) { 
                    ans.push_back(string(sv));
                }
            } else {
                hash.insert(sv);
            }
        }
        return ans;

    }
};