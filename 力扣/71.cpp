class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;//用vector模拟栈
        stringstream ss(path);//将字符串转化为流
        string split;
        string simplifyPath;

        while(getline(ss,split,'/'))
        {
            if(split=="."||split=="")
            {
                continue;
            }else if(split=="..")
            {
                if(!stack.empty())
                {
                    stack.pop_back();
                }
            }else{
                stack.push_back(split);
            }
        }

        for(auto &i:stack)
        {
            simplifyPath+='/'+i;
        }

        return stack.empty()? "/":simplifyPath;

    }
};