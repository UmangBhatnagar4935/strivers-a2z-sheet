#include <bits/stdc++.h>
using namespace std;



/* use topo sort algorithm 
   - topo sort only apply for directed acyle graphs 
   - a graph don't have any cycle then you are able to traversal the complete graph
   - a grpah have cyle, you are not able to traveral the complete graphs using topo sort algoritm 

*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       
       // same code of khan's algoritm,
	     vector<int> indegree(V);
	     for(int i = 0; i<V; i++){
	         for(auto it : adj[i]){
	             indegree[it] ++;
	         }
	     }
	     
	     queue<int> q;
	     
	     for(int i = 0; i<V; i++){
	         if(indegree[i] == 0){
	             q.push(i);
	         }
	     }
	     
	     
	     int count = 0;
	     
	     while(!q.empty()){
	         int node = q.front();
	         q.pop();
	         
	         count = count + 1;
	         
	         for(auto it : adj[node]){
	             indegree[it] --;
	             if(indegree[it] == 0){
	                 q.push(it);
	             }
	         }
	     }
	     
	     if(count == V){
	         return false;
	     }
	     return true;
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
