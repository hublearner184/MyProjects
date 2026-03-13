#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    unordered_map<string,int> subTrees;
    vector<TreeNode*> res;
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root){
        subTrees.clear();
        res.clear();
        serialize(root);
        return res;
    }

    string serialize(TreeNode* root){
        if(root == nullptr){
            return "#";
        }

        string left = serialize(root->left);
        string right = serialize(root->right);
        string myself = left + "," + right + "," + to_string(root->val);

        int freq = subTrees[myself];
        if(freq == 1){
            res.push_back(root);
        }
        subTrees[myself] = freq + 1;
        return myself;
    }
};
TreeNode* buildTree(const vector<string>& nodes){
    if(nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < nodes.size()){
        TreeNode* curr = q.front();
        q.pop();

        if(nodes[i] != "null"){
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if(i < nodes.size() && nodes[i] != "null"){
            curr->right = new TreeNode
        }
    }
}