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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size() == 0){
            return NULL;
        }

        //后序遍历数组最后一个元素就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        //叶子节点
        if(postorder.size() == 1){
            return root;
        }

        int delimiterIndex;
        for(delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++){
            if(inorder[delimiterIndex] == rootValue){
                break;
            }
        }
        //切割中序数组
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());
        postorder.resize(postorder.size() - 1);

        //切割后序数组
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0){
            return NULL;
        }
        return traversal(inorder, postorder);
    }
};

//也是这个思路，但是做法更简单
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post = postorder;
        int index = postorder.size() - 1;
        return build(inorder, 0, inorder.size() - 1, index);
    }

private:
    TreeNode* build(vector<int>& inorder, int start, int end, int& index) {
        if (start > end) {
            return nullptr;
        }
        
        int rootVal = post[index--];
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndex = find(inorder.begin() + start, inorder.begin() + end, rootVal) - inorder.begin();
        
        root->right = build(inorder, rootIndex + 1, end, index);
        root->left = build(inorder, start, rootIndex - 1, index);
        
        return root;
    }

    vector<int> post;
};
