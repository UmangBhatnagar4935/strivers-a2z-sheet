#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        // size of the matrix
        int n = image.size();
        int m = image[0].size();
        
        // store the starting color
        int starting_color = image[sr][sc];
        // i don't want to change orginal data (orginal matrix )
        // we will create the copy matrix
        vector<vector<int>> copymatrix = image;
        queue<pair<int,int>> q;
        
        // push into the queue and convert into the new color 
        q.push({sr,sc});
        copymatrix[sr][sc] = newColor;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // we can go 4- directionally to those pixles ( also with the same color starting color)
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            
            for(int index = 0; index < 4; index++){
                int newrow = delrow[index] + row;
                int newcol = delcol[index] + col;
                
                 if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m 
                 && image[newrow][newcol] == starting_color
                  && copymatrix[newrow][newcol] != newColor){
                      // push into the queue data stucture and colored by new color
                      q.push({newrow,newcol});
                      copymatrix[newrow][newcol] = newColor;
                  }
            }
        }
        return copymatrix;
    }
};

// congratulation - you have done your taks perfectly 

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}