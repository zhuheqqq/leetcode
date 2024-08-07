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
    void traversal(TreeNode* root) {
        if(root == NULL){
            return;
        }
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        if(vec.size() < 2) {
            return 0;
        }
        int ans = INT_MAX;
        for(int i = 1; i < vec.size(); i++) {
            ans = min(ans, vec[i] - vec[i - 1]);
        }
        return ans;
    }
};