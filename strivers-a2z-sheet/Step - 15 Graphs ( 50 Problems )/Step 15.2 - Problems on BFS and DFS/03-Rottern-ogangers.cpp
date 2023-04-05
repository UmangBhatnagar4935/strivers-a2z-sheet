#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
             // case - 1 
            queue<pair<pair<int,int>,int>>q;
            
            int n =grid.size();
            int m =grid[0].size();
            
            vector<vector<int>>ans=grid;
            
             for(int i=0;i<n;i++){
                 for(int j=0;j<m;j++){
                     // already rottern oranges push into the queue 
                     if(grid[i][j]==2){
                         q.push({{i,j},0});
                   }
                 }
        }
        // case - 02
        // pop the element and go all 4-directions
           int timee=0;
            while(!q.empty()){
                auto row=q.front().first.first;
                auto col=q.front().first.second;
                int qtime=q.front().second;
                q.pop();
    
                timee=max(timee,qtime);

                int delrow[]={-1,0,1,0};
                int delcol[]={0,1,0,-1};

                for(int i=0;i<4;i++){
    
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    if(nrow>=0 && nrow< n && ncol>=0 && ncol< m  &&grid[nrow][ncol]==1 && ans[nrow][ncol]!=2 ){
                        ans[nrow][ncol]=2;
                        q.push({{nrow,ncol},qtime+1});
                    }
                }
        }
            // case - 03
            // after roottern if all the guys fresh then return -1
            for(int i=0;i<n;i++ ){
                for(int j=0;j<m;j++) {
                    if(ans[i][j]==1){
                        return -1;
                    }
                }
            }
            return  timee;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
