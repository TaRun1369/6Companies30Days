class Solution {
public:
int dp[10005][105];
    int recur(int n,int curr,int kahatak){
        if( n == 0) return 0;
        if(n < 0) return 1e9;
        if(curr > kahatak) return 1e9;
            if(dp[n][curr] !=  -1) return dp[n][curr];
        int take = 1 + recur(n - curr*curr,curr,kahatak);
        int nottake = recur(n , curr + 1,kahatak);
        return dp[n][curr] = min(take,nottake);
    }
    int numSquares(int n) {
        int kahatak = sqrt(n);
       memset(dp,-1,sizeof(dp));
        return recur(n,1,kahatak);
    }
};