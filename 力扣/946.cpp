class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int size=pushed.size();
        stack<int> st;
        int i,j;

        for(i=0,j=0;i<size;i++)
        {
            st.push(pushed[i]);
            while(!st.empty()&&st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            
            
        }


        return st.empty();

    }
};