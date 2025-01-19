#include <iostream>
using namespace std;

struct BST_node
{
    int data;
    BST_node* lchild;
    BST_node* rchild;
    BST_node(int x) : data(x), lchild(nullptr), rchild(nullptr){}
};

class BST
{
    private:
        BST_node* root;
    public:
        BST() : root(nullptr){}

        void insert(BST_node*& root, int x)
        {
            if(root == nullptr)
            {
                root = new BST_node(x);
                return;
            }

            else if(x < root->data) insert(root->lchild, x);
            else if(x > root->data) insert(root->rchild, x);
            else return;

            return;
        }

        bool search(BST_node* root, int x) {
            if (root == nullptr) return false;  // 树为空，返回 false
            if (x == root->data) return true;   // 找到元素，返回 true
            else if (x < root->data) return search(root->lchild, x); // 在左子树查找
            else return search(root->rchild, x); // 在右子树查找
        }

        int height(BST_node* root)
        {
            if(root == nullptr) return 0;
            int left = height(root->lchild);
            int right = height(root->rchild);
            // if(abs(left-right) > 1) flag = false;    这里添加这一行可以便捷的判断二叉树是否平衡
            return max(left, right) + 1;
        }
};