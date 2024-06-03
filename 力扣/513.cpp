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
 //dfs
class Solution {
public:

    void dfs(TreeNode* root, int height, int &curValue, int &curHeight) {
        if (root == NULL) {
            return;
        }

        height++;

        dfs(root->left, height, curValue, curHeight);
        dfs(root->right, height, curValue, curHeight);

        if(height > curHeight) {
            curHeight = height;
            curValue = root->val;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        int curValue, curHeight = 0;
        dfs(root, 0, curValue, curHeight);
        return curValue;
    }
};