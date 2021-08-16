// Depth First Search 


#include <map>
#include <list>
#include <iostream>
// using namespace std;

/* Graph class representing a directed weigted graph using adjancency
 list */

class Graph{
public:
    std::map<int, bool> visited;
    std::map<int, std::list<int>> adj;


    void addEdge(int v, int w);
    void DFSUtil(int v);
    void DFS();
    
};


void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v){

    visited[v] = true;
    std::cout << v << std::endl;

    std::list<int>::iterator i;

    for(i=adj[v].begin(); i!=adj[v].end();++i){
        if(!visited[*i])
            DFSUtil(*i);
    }
}

void Graph::DFS(){

    for(auto i:adj){
        if(visited[i.first] == false){
            DFSUtil(i.first);
        }
    }
}

int main(int argc, char** argv){
    Graph g;

    g.addEdge(0,1);
    g.addEdge(0,9);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(9,3);

    g.DFS();
    return 0;
}