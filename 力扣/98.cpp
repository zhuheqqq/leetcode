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
 //感觉直接中序遍历就可以  试一下
class Solution {
private:
    long pre=LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }

        if(!isValidBST(root->left))
        {
            return false;
        }

        // 访问当前节点：如果当前节点小于等于中序遍历的前一个节点，说明不满足BST，返回 false；否则继续遍历。
        if (root->val <= pre) {
            return false;
        }
        
        pre = root->val;
        
        // 访问右子树
        return isValidBST(root->right);

    }
};