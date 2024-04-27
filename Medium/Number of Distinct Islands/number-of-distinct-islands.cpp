//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>> &vec,int basei,int basej){
    //   if(vis[i][j] == 1) return;
     int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        
        // i -= basei;
        // j -= basej;
        vec.push_back({i - basei,j - basej});
        
        // if(i < grid.size()-1){
        //     dfs(i+1,j,grid,vis,vec,basei,basej);
        // }
        // if(j < grid[0].size()-1){
        //     dfs(i,j+1,grid,vis,vec,basei,basej);
        // }
        // if(i > 0){
        //     dfs(i - 1,j,grid,vis,vec,basei,basej);
        // }
        // if(j > 0){
        //     dfs(i,j-1,grid,vis,vec,basei,basej);
        
        // }
        vector<int> delr = {0,1,0,-1},delc = {1,0,-1,0};
        
        for(int k = 0;k<4;k++){
            int nrow = i + delr[k];
            int ncol = j + delc[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,grid,vis,vec,basei,basej);
            }
        }
        
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code herein
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    // for(auto it : vec){
                    //     cout<<it.first<<"   -  "<<it.second<<" ";
                    // }
                    s.insert(vec);
                }
            }
        }
        
        return s.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends