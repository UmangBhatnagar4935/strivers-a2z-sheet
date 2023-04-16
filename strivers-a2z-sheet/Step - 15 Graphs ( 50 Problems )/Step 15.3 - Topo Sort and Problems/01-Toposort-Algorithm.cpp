#include <bits/stdc++.h>
using namespace std;



/*

#Algorithm of Kahn's -
1 - those who complete their dfs calls push into the stack 
2 - move the node stack into result array
*/


class Solution{
    private:
    void DFS(int node, vector<int> & vis, stack<int> & st, vector<int> adj[]){
        // mark visted 
        vis[node] = 1;
        
        // go the ajdlist nodes all
        for(auto it : adj[node]){
            if(!vis[it]){
                DFS(it,vis,st,adj);
            }
        }
        // remember this point : when people who are completed their DFS calls push into the stack
        st.push(node);
        
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    vector<int> result_array;
	    stack<int> st;
	    
	    for(int node = 0; node < V; node++){
	        if(!vis[node]){
	            DFS(node,vis,st,adj);
	        }
	    }
	    
	    while(!st.empty()){
	        result_array.push_back(st.top());
	        st.pop();
	    }
	    return result_array;
	}   
};

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