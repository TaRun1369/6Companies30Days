class Solution {
public:
    
    // dp vector store precalculated result of <index,sum>
    // max array size 20 and max element sum 1000 and so min element sum 1000
    // makes sum range 0 to  1000+1000 = 2000
    int dp[21][2001];
    
    // recursion from 0 to end of nums array taking +nums[i] and -nums[i] value
    int dfs(int index, vector<int>& nums, int &S, int sum)
    {
        // reached to the end of array 
        // return 1 if S==sum, otherwise return 0
        if(index==nums.size())
            return sum==S?1:0;

        // return precalculted result
        // to avoid negative index we add 1000 with sum
        if(dp[index][sum+1000]!=-1) return dp[index][sum+1000];
        
        int count = 0;
        
        // call recursion for taking both +nums[i] and -nums[i] values
        // and updated running sum as sum+nums[i] and sum-nums[i]
        
        count+= dfs(index+1,nums,S,sum+nums[index]);
        count+= dfs(index+1,nums,S,sum-nums[index]);
        
        return dp[index][sum+1000] = count;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        
        // set -1 to all dp values
        memset(dp,-1,sizeof(dp));
        
        // all possible ways to reach target 
        return dfs(0,nums,S,0);
    }
};