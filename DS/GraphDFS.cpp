#include <iostream>
#include <vector>
using namespace std;

class Vertex{
public:
    int id;
    vector<Vertex*> children;
};
void traverse(Vertex* start,vector<bool>& visited){
    if(start == nullptr) return;
    if(visited[start->id] == true) return;

    visited[start->id] == true;
    cout << "visit" << start->id << endl;
    for( auto neighbor : start->children){
        traverse(neighbor,visited);
    }
}
