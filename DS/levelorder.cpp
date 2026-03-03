#include <iostream>
#include <queue>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
/*写法简单 但不常用 因为无法知道当前节点在第几层 算不出深度
void LevelOrderTraverse(TreeNode* root){
    if(root == nullptr){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        cout << cur->val << endl;
        if(cur->left != nullptr)
            q.push(cur->left);
        if(cur->right != nullptr)
            q.push(cur->right);
    }
}
*/
/*常见写法
void LevelOrderTraverse(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    int depth = 1;
    while(!q.empty()){
        int m = q.size();
        for(int i=0;i < m;i++){
            TreeNode* cur = q.front();
            q.pop();
            cout << "depth = " << depth << ",val =" << cur->val << endl;
            if(cur->left != nullptr){
                q.push(cur->left);
            }
            if(cur->right != nullptr){
                q.push(cur->right);
            }
        }
        depth++;
    }
}
*/
//路径权重和写法
class State{
public:
    TreeNode* node;
    int depth;
    State(TreeNode* node,int depth):node(node),depth(depth){}
};
void LevelOrderTraversal(TreeNode* root){
    queue<State> q;
    q.push(State(root,1));
    while(!q.empty()){
        State cur = q.front();
        q.pop();
        cout << "depth =" << cur.depth << ", val = " << cur.node->val << endl;
        if(cur.node->left != nullptr){
            q.push(State(cur.node->left,cur.depth + 1));
        }
        if(cur.node->right != nullptr){
            q.push(State(cur.node->right,cur.depth + 1));
        }
    }
}
