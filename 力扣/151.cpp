class Solution {
public:
    void removeExitSpace(string &s){
        int slow=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')//遇到非空格就进入删除所有空格
            {
                if(slow!=0)//如果slow不是第一个单词
                {
                    s[slow++]=' ';//在单词前面加上空格
                }

                while(i<s.size()&&s[i]!=' ')
                {
                    s[slow++]=s[i++];
                }
            }
        }

        s.resize(slow);
    }

    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        removeExitSpace(s);
        reverse(s,0,s.size()-1);

        int start=0;
        for(int i=0;i<=s.size();i++)
        {
            if(s[i]==' '||i==s.size())
            {
                reverse(s,start,i-1);
                start=i+1;
            }
            
        }

        return s;
    }
    
};