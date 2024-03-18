class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        int i = 0,j = 0;
        int n = nums.size();
        while(i<n && j < n){
            while(j <= i && sum < 0){
                sum -= nums[j];
                j++;
            }
            sum += nums[i];
            maxi = max(maxi,sum);
            i++;
        }
        return maxi;
    }
};