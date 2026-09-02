#include <iostream>
#include <vector>
using namespace std;

void DFS(int node,vector<vector<int>> &adj,vector<bool> &visited){
    visited[node]=true;
    cout<<node<<" ";

    for(int neighbour: adj[node]){
        if(!visited[neighbour]){
            DFS(neighbour,adj,visited);
        }
    }
}

int main(){
    int V,E;
    cout<<"Enter number of vertices and edges ";
    cin>>V>>E;
    vector<vector<int>>adj(V);
    cout<<"Enter edges "<<endl;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V,false);
    int components=0;
    cout<<"\nConnected components :"<<endl;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            components++;
            cout<<" Component "<<components<<":";
            DFS(i,adj,visited);
            cout<<endl;
        } 
    }
    cout<<"\nTotal Connected Components = "<<components<<endl;

    return 0;
}