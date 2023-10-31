/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
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
    void  preorder(struct TreeNode* root,int &ans){
        if(root==nullptr)
        {
            return;
        }
        ans++;
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    int countNodes(TreeNode* root) {
        int ans=0;
        preorder(root,ans);
        return ans;

    }

};
// @lc code=end

