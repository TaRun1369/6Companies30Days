class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n+1,0);
        long m = 1e9 + 7;
        long currsharing = 0;
        long ans = 0;
        dp[1] =1;

        for(int i = 2;i<=n;i++){
            long noofdelaywale = dp[max(i - delay,0)]%m;
            long noofforgetwale = dp[max(i - forget,0)]%m;
            currsharing += (noofdelaywale - noofforgetwale)%m;

            dp[i] = currsharing%m;


        }

        for(int i = n - forget + 1;i<=n;i++ ){
            ans +=dp[i]%m;
        }
        return ans%m;
    }
};