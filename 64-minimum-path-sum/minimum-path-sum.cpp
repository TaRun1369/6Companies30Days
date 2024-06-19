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
        vector<vector<int>> dp(n,vector<int> (m,1e7));
        if(n == 1 && m == 1) return grid[0][0];
        // return recur(grid,n-1,m-1,dp);
        dp[0][0] = grid[0][0];

        // dp[0][1] = grid[0][0] + grid[0][1];
        // dp[1][0] = grid[0][0] + grid[1][0];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int top= 1e7,left = 1e7;
                if(i - 1 >= 0)
                top = grid[i][j] + dp[i-1][j];
                if(j-1 >= 0)
                left = grid[i][j] + dp[i][j-1];

                dp[i][j] = min(top,min(left,dp[i][j]));
            }
            
        }
        
        return dp[n-1][m-1];
    }
};