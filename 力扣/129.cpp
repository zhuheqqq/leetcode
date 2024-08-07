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
    vector<int> vec;
    int  traserval(TreeNode* root, int presum) {
        if(root == NULL) {
            return 0;
        }
        int sum = presum * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr) {
            return sum;
        }else {
           return  traserval(root->left, sum) + traserval(root->right, sum);
        }
        
    }
    int sumNumbers(TreeNode* root) {
        return traserval(root, 0);
    }
};