#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
};
class Solution{
public:
    vector<int> input;
    vector<int> output;
    Solution(vector<int> a): input(a){}
    void preorderTraversal(TreeNode* root){
        if(root == nullptr){
            return;
        }
        else{
            output.push_back(root->val);
        }
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    void outputs(){
        for(int i; i < output.size();i++){
            cout << output[i] << "," << endl;
        }
    }
    void createTree(TreeNode* root){
        for(int i =0;i < input.size();i++)
           
    }
};
int main(){
    vector<int> input = {1,2,3,4,5,NULL,8,NULL,NULL,6,7,9};
    Solution(input);

}