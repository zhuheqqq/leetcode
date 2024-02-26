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
private:
    void traversal(TreeNode* cur,vector<int> &path,vector<string> &result)
    {
        path.push_back(cur->val);//将最后一个节点加入path

        //如果是叶子节点
        if(cur->left==nullptr&&cur->right==nullptr)
        {
            string spath;
            for(int i=0;i<path.size()-1;i++)
            {
                spath+=to_string(path[i]);
                spath+="->";
            }
            spath+=to_string(path[path.size()-1]);
            result.push_back(spath);
            return;
        }

        if(cur->left){
            traversal(cur->left,path,result);
            path.pop_back();//如果从上一行代码出来代表左子树已经全部遍历完毕，所以回溯
        }

        if(cur->right){
            traversal(cur->right,path,result);
            path.pop_back();
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if(root==nullptr)
        {
            return result;
        }
        traversal(root,path,result);
        return result;

    }
};