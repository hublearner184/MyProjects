#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int val;
    vector<Node*> childern;
};

void traverse(Node* root){
    if(root == nullptr){
        return;
    }
    for(Node* child : root->childern){
        traverse(child);
    }
}