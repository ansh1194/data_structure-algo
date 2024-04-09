#include <iostream>
#include <list>

class Graph{
public:
    int V;  //Number of vertices

    std::list<int>* adj;    //Pointer to an array containing adjancency list

    Graph(int V);       //Constructor

    void addEdge(int v, int w);     //Function to add an edge

    void BFS(int s);    //Function for BFS traversal
};



Graph::Graph(int V){

    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){

    bool* visited = new bool[V];
    for(int i = 0; i< V; i++){
        visited[i] = false;
    }

    std::list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    std::list<int>::iterator i;

    while(!queue.empty()){
        s = queue.front();
        std::cout << s << std::endl;

        queue.pop_front();

        for(i = adj[s].begin(); i!=adj[s].end();i++){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

}


int main(int argc, char** argv){

    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    g.BFS(2);
    return 0;
}
