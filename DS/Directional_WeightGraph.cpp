#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class WeightedDigraph{
public:
    struct Edge{
        int to;
        int weight;

        Edge(int to,int weight){
            this->to = to;
            this->weight =weight;
        }
    };
private:
    vector<vector<Edge>> graph;
public:
    WeightedDigraph(int n){
        graph = vector<vector<Edge>>(n);
    }
    void addEdge(int from,int to,int weight){
        graph[from].emplace_back(to,weight);
    }
    void removeEdge(int from,int to){
        for(auto it = graph[from].begin();it != graph[from].end();++it){
            if(it->to == to){
                graph[from].erase(it);
                break;
            }
        }
    }
};