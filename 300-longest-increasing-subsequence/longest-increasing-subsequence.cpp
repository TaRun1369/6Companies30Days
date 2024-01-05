class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int dp[nums.size()]; // dp[i] represents i+1'th length LIS ending at minimum integer dp[i]
    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
       
        int position = lower_bound(dp, dp + ans, nums[i]) - dp;
        dp[position] = nums[i];

        if (position == ans)
        {
            ans++;
        }
    }

    return ans;
    }
};