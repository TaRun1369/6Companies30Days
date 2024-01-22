class Solution {
public:
    int minMoves2(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int n = nums.size(),j = n-1,i = 0;
       int ans = 0;
       while(i < j){
           ans += (nums[j] - nums[i]);
           i++;
           j--;
       }
       return ans;
    }
};