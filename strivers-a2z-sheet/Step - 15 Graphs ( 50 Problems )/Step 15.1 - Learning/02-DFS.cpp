
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
   void DFS(int node, vector<int>& vis, vector<int> & container, vector<int> adj[]){
       
       // mark visted and push into the answer array
       vis[node] = 1;
       container.push_back(node);
       
       for(auto it : adj[node]){
           if(!vis[it]){
               DFS(it,vis,container,adj);
           }
       }
   }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> container;
        vector<int> vis(V,0);
        DFS(0,vis,container,adj);
        return container;
    }
};

//{ Driver Code Starts.
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
