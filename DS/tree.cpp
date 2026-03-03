#include <iostream>

class TreeNode{
    public:
    int value;
    TreeNode* leftchild;
    TreeNode* rightchild;

    TreeNode(int x) : value(x),leftchild(nullptr),rightchild(nullptr){} //构造函数
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->leftchild = new TreeNode(2);
    root->rightchild = new TreeNode(3);
    root->leftchild->leftchild = new TreeNode(4);
    root->rightchild->leftchild = new TreeNode(5);
    root->rightchild->rightchild = new TreeNode(6);
}