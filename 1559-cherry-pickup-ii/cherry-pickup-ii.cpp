class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>> (c,vector<int>(c,0)));
    for(int j1 = 0;j1<c;j1++){
        for(int j2 = 0;j2 < c;j2++){
            if(j1 == j2){
                dp[r-1][j1][j2] = grid[r-1][j1];
            }
            else{
                dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }
    }

    for(int i = r-2;i>= 0;i--){
        for(int j1 = 0;j1<c;j1++){
            for (int j2 = 0; j2 < c; j2++) {
                 int maxi = INT_MIN;
                    for(int dx = -1;dx < 2;dx++){
                        for(int dy = -1;dy < 2;dy++){
                            int val;
                            if(j1 == j2){
                               val=  grid[i][j1] ;
                            }
                            else{
                                val = grid[i][j1] + grid[i][j2] ;
                            }

                            if(j1 + dx >= 0 && j2 + dy >= 0 && j1 + dx < c && j2 + dy < c){
                                val += dp[i+1][j1+dx][j2 + dy];
                            }
                            else val += INT_MIN;
                            maxi = max(maxi,val);

                        }
                    }
                     dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][c-1];
    }
};