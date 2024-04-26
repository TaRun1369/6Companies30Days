class Solution {
public:
    int recur(int i,int prev,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i == 0){
            int mini = INT_MAX;
            for(int k = 0;k<grid[0].size();k++){
                if(k != prev)
                mini = min(mini,grid[0][k]);
            }
            return mini;
        }
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int take = INT_MAX;
        int minii = INT_MAX;
        for(int k = 0;k<grid[0].size();k++){
            
            // minii = min(minii,grid[i][k]);
            // if(grid[i][k] < mini){

            // }
            if(k != prev)
            take = min(take,grid[i][k] + recur(i-1,k,grid,dp));
        }
        return dp[i][prev + 1] = take;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return recur(n-1,-1,grid,dp);

    }
};