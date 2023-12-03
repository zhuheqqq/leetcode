class Solution {
public:
    string makeGood(string s) {
        stack<char> x_stack;
        string result;

        for(int i=0;i<s.size();i++)
        {
            if(!x_stack.empty())
            {
                if(abs(s[i]-x_stack.top())==32)
                {
                    x_stack.pop();
                }else{
                    x_stack.push(s[i]);
                }
            }else{
                x_stack.push(s[i]);
            }
        }
        
        while (!x_stack.empty()) {
            result += x_stack.top();
            x_stack.pop();
        }

        reverse(result.begin(), result.end());

        return result;

    }
};