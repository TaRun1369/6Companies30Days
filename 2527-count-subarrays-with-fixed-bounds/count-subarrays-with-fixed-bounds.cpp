class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long minp = -1,maxp = -1,culprit = -1,ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] < minK || nums[i] > maxK){
                culprit = i;
            }
            if(nums[i] == minK) minp = i;
            if(nums[i] == maxK) maxp = i;

            int sm = min(minp,maxp);

            int temp = sm - culprit;

            ans+= (temp<=0) ? 0:temp;
        }
        return ans;
    }
};