class Solution {
public:
int dp[10005];
int recur(int n){
    if( n== 0) return 0;
    if(dp[n] != -1) return dp[n];
    int mini = INT_MAX;
    for(int i = 1;i*i <= n;i++){
        int ans = 1 + recur(n-i*i);
        mini = min(ans,mini);
    }
    return dp[n] = mini;
}
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return recur(n);
    }
};