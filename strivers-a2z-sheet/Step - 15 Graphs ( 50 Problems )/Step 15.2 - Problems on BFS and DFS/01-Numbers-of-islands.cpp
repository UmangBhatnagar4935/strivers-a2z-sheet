#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
   int BFS(int row, int col, vector<vector<int>> & vis ,vector<vector<char>> & grid){
       
       queue<pair<int,int>> q;
       
         int n = grid.size();
        int m = grid[0].size();
        
       
       // crate the queue data stucture and mark visted 
       q.push({row,col});
       vis[row][col] = 1;
       
       while(!q.empty()){
           int row = q.front().first;
           int col = q.front().second;
           
           q.pop();
           
        // in the leetcode questons according they want to go only 4 directions    
        //   int delrow[] = {-1,0,1,0}; 
        //   int delcol[] = {0,-1,0,1};
           
           //adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
            // go the four directions using loop [-1,0,0,1];
               for(int delrow = -1; delrow <=1; delrow++){
                for(int delcol = -1; delcol <=1; delcol++){
                    int newrow = delrow + row;
                    int newcol = delcol + col;
                    
                   // we can control the 3-conditons 
                   if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && 
                   !vis[newrow][newcol] && grid[newrow][newcol] == '1'){
                       q.push({newrow,newcol});
                       vis[newrow][newcol] = 1; 
                   }
                }
            }
        }
       
   }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
      // crate the visted array
      vector<vector<int>> vis(n,vector<int>(m,0));
        
        int islands = 0;
        
        for(int row = 0; row < n; row ++){
            for(int col = 0; col < m; col ++){
                if(grid[row][col] == '1' && vis[row][col] == 0){
                    BFS(row,col,vis,grid);
                    islands++;
                }
            }
        }
        return  islands;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
