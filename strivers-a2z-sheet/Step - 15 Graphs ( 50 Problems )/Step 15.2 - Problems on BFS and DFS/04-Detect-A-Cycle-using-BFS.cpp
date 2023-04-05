#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
   // we want to bollean output
   bool cyclecheck(int node, vector<int> & vis, vector<int> adj[]){
       
       queue<pair<int,int>> q;
       q.push({node,-1});
       // starting node does't have any parents node so we will assume -1
       vis[node] = 1;
       
       while(!q.empty()){
           int node = q.front().first;
           int parent = q.front().second;
           
           q.pop();
           
           for(auto it : adj[node]){
               if(!vis[it]){
                   // node become = parents node
                   // new node become = current node
                   q.push({it,node});
                   vis[it] = 1;
               }else if( parent != it){
                   return true;
               }
           }
       }
       return false;
   }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       // start code
       vector<int> vis(V,0);
       
       for(int node = 0; node < V; node++){
           if(!vis[node]){
               // if graphs any components contain cycle then we can return true;
               if(cyclecheck(node,vis,adj) == true){
                  return true; 
               }
           }
       }
       return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}