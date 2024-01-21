class Solution {
public:
    int recur(int curr,vector<int> &nums,vector<int> &dp){
        if(curr >= nums.size()){
            return 0;
        }
        if(dp[curr] != -1) return dp[curr];
        int pick = nums[curr] + recur(curr + 2,nums,dp);
        int notpick = recur(curr + 1,nums,dp);

        return dp[curr] = max(pick,notpick);

    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return recur(0,nums,dp);
    }
};