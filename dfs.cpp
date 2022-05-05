#include <bits/stdc++.h>
using namespace std;
map<int, bool> visited;
map<int, vector<int> > adj;
void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(int i){
    visited[i]=true;
    cout<<i<<endl;
    for(auto v:adj[i]) if(!visited[v]) dfs(v);
}
int main(){
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    dfs(0);
}