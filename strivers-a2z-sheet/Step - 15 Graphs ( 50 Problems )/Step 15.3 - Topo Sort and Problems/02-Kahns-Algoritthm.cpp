#include <bits/stdc++.h>
using namespace std;

/*

#Algorithm of Kahn's -
1- insert all the nodes with indegree 0 into the queue
2-take them out the queue 
3- reduce the number of indegree

 what is number of indegree?
 number of incoming edages that is conncected to the node 

*/


class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    // create the in-dgree array
	    // store the number of in-degree
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
	     
	     vector<int> resultArray;
	     
	     while(!q.empty()){
	         int node = q.front();
	         q.pop();
	         
	         resultArray.push_back(node);
	         
	         for(auto it : adj[node]){
	             indegree[it] --;
	             if(indegree[it] == 0){
	                 q.push(it);
	             }
	         }
	     }
	    
	    return resultArray;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}