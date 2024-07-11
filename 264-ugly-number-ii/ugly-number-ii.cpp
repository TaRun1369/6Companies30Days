class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        int i2 = 1,i3 = 1,i5 = 1;
        dp[1] = 1;
        
        for(int i= 2;i<=n;i++){
            int uglyi2 = dp[i2]*2;
            int uglyi3 = dp[i3]*3;
            int uglyi5 = dp[i5]*5;
            int mini = min(uglyi2,min(uglyi3,uglyi5));
             dp[i] = mini;
            if(uglyi2 == mini) i2++;
            if(uglyi3 == mini) i3++;
            if(uglyi5 == mini )i5++;

        }
        return dp[n];
    }
};