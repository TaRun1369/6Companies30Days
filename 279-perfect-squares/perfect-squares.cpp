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
        memset(dp,0,sizeof(dp));
        // for()
        // return recur(n);
        
        for(int i = 1;i<=n;i++){
                    int mini = INT_MAX;
            for(int j = 1;j*j <= i;j++){
                int ans = 1 + dp[i-j*j];
                mini = min(ans,mini);
            }
            dp[i] = mini;
        }
        return dp[n];

    }
};