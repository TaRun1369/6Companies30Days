class Solution {
public:
    int recur(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0) return 1e7;
        if(j < 0) return 1e7;
        if(dp[i][j] != -1) return dp[i][j];
        int top= 1e7,left = 1e7;
        if(i - 1 >= 0)
        top = grid[i][j] + recur(grid,i-1,j,dp);
        if(j-1 >= 0)
        left = grid[i][j] + recur(grid,i,j-1,dp);

        return dp[i][j] = min(top,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return recur(grid,n-1,m-1,dp);
    }
};