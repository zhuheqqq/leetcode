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

//中序遍历排序再挂回去
class Solution {
public:
    vector<int> vec;
    
    void helper(TreeNode* root, int flag) {
        if(root == nullptr) {
            return;
        }
        helper(root->left, flag);
        if(flag == 1) {
            vec.push_back(root->val);
        }else if(flag == 2) {
            root->val = vec.front();
            vec.erase(vec.begin());
        }
        
        helper(root->right, flag);
    }
    void recoverTree(TreeNode* root) {
        int flag = 1;
        helper(root, flag);
        sort(vec.begin(), vec.end());
        flag = 2;
        helper(root, flag);

    }
};

//遍历找到时直接交换
class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        // 中序遍历：左 -> 根 -> 右
        inorder(root->left);
        
        // 找到顺序错误的第一个和第二个元素
        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;  // 第一个比下一个大的元素
            }
            second = root;  // 最后一个比前一个小的元素
        }
        
        prev = root;  // 更新 prev 为当前节点
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        // 进行中序遍历并找到两个被交换的节点
        inorder(root);
        
        // 交换两个节点的值以恢复 BST
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};
