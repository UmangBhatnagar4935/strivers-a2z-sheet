#include <bits/stdc++.h>
using namespace std;

/* NOtes :
 inorder to understand and solve any questions in graphs data structure,
   we need to understand first of all, traversal algortim
   today, we will learning bfs algoritm 
*/

/*
1- inorder to print level wise,we need queue 
2- we don't want to take any particular element/node again again!
   we need to visted array

- push into the queue start node and mark visted
- when you pop this node, push into the result array
- and checkout the who are neighbours of this node (WRTN)
*/


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       // start code
       vector<int> arr;
       vector<int> vis(V,0);
       queue<int> q;
       
       q.push(0);
       vis[0] = 1;
       
       while(!q.empty()){
           int node = q.front();
           q.pop();
           
           arr.push_back(node);
           
           // go the all connected node 
           for(auto it: adj[node]){
               if(!vis[it]){
                   q.push(it);
                   vis[it] = 1;
               }
           }
       }
       return arr;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
    
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
