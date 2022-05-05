#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > adj;
void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void bfs(int i){
    vector<bool> visited(adj.size(),false);
    queue<int> q;
    q.push(i); 
    visited[i]=true;
    int f;
    while(!q.empty()){
        f=q.front();
        cout<<f<<endl;
        q.pop();
        for(auto v:adj[f]){
            if(!visited[v]){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
int main(){
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    bfs(0);
}