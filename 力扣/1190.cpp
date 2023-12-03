class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> x_stack;
        string st;

        for(auto &ch:s)
        {
            if(ch=='(')
            {
                x_stack.push(st);
                st="";
            }else if(ch==')')
            {
                reverse(st.begin(),st.end());
                st=x_stack.top()+st;
                x_stack.pop();
            }else{
                st.push_back(ch);
            }
        }

        return st;


    }
};