class Solution {
public:
    int recur(vector<int> &nums,int target,int ind){

        if(ind == -1){
            if(target == 0) return 1;
            else return 0;
        }
        if(ind < 0) return 0;

        int sum = recur(nums,target + nums[ind],ind - 1);
        int minus = recur(nums,target - nums[ind],ind - 1);
        return sum + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recur(nums,target,nums.size() - 1);
    }
};