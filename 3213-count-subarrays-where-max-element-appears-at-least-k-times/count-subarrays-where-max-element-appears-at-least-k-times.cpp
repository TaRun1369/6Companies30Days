class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int j = 0,prev = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == maxi) k--;
            if(k == 0){
                while(j < n && k == 0){
                    if(nums[j] == maxi) k++;
                    prev++;
                    j++;
                }
            }
            ans += prev;
        }
        return ans;
    }
};