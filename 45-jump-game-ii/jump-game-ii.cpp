class Solution {
public:
    int recur(vector<int> &nums,int i,int n,vector<int> &dp){
        if(i >= n) return 1e7;
        if(i == n-1) return 1;
        if(dp[i] != -1) return dp[i];
        int j = i + nums[i];
        int ans = 1e7;
        for(int k = i + 1;k <= j;k++){
            ans = min(ans,1+recur(nums,k,n,dp));
        }

        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return recur(nums,0,n,dp) - 1;
    }
};