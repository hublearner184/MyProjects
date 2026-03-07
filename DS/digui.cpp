#include <iostream>

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
};

void traverse(TreeNode* root){
    if(root == nullptr){
        return;
    }
    //preorder code
    traverse(root->left);
    //inorder code
    traverse(root->right);
    //postorder code
}
int main(){

}