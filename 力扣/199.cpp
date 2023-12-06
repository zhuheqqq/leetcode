/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        if(root!=nullptr)
        {
            que.push(root);
        }
        vector<stack<int>> result;
        while(!que.empty())
        {
            int size=que.size();
            stack<int> vec;

            for(int i=0;i<size;i++)
            {
                TreeNode* node=que.front();
                que.pop();
                vec.push(node->val);
                if(node->left)
                {
                    que.push(node->left);
                }
                if(node->right)
                {
                    que.push(node->right);
                }

            }
            result.push_back(vec);
        }

        vector<int> v;
        for(int i=0;i<result.size();i++)
        {
            v.push_back(result[i].top());

        }

        return v;

    }
};