/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        if(root!=nullptr)
        {
            que.push(root);
        }

        vector<vector<int>> vec;
        while(!que.empty())
        {
            int size=que.size();
            vector<int> res;
            for(int i=0;i<size;i++)
            {
                Node* node=que.front();
                que.pop();
                res.push_back(node->val);
                for(auto& ch:node->children)
                {
                    que.push(ch);
                }
            }
            vec.push_back(res);
        }

        return vec;
        
    }
};