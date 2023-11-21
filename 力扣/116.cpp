/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//广度优先遍历用队列，深度优先遍历用递归
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> Q;

        if(root==NULL)
        {
            return root;
        }

        Q.push(root);

        while(!Q.empty())//当队列不为0时
        {
            int size=Q.size();

            for(int i=0;i<size;i++)//遍历这一层
            {
                Node* node=Q.front();
                Q.pop();

                if(i<size-1)//i代表遍历到每一层的第几个
                {
                    node->next=Q.front();
                }

                if(node->left!=NULL)
                {
                    Q.push(node->left);
                }

                if(node->right!=NULL)
                {
                    Q.push(node->right);
                }
            }
        }

        return root;
        
    }
};