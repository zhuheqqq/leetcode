class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true; // 空树是对称的
        }
        
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* leftSubtree, TreeNode* rightSubtree) {
        if (leftSubtree == nullptr && rightSubtree == nullptr) {
            return true; // 左右子树都为空，对称
        }
        
        if (leftSubtree == nullptr || rightSubtree == nullptr) {
            return false; // 一个为空，一个不为空，不对称
        }
        
        if (leftSubtree->val != rightSubtree->val) {
            return false; // 左右子树根节点的值不相等，不对称
        }
        
        // 递归比较左子树的左子树和右子树的右子树，以及左子树的右子树和右子树的左子树
        return isMirror(leftSubtree->left, rightSubtree->right) && isMirror(leftSubtree->right, rightSubtree->left);
    }
};
