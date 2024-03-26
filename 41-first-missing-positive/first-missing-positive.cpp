class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int ii = 0;
        while(ii < n){
            if(nums[ii] > 0 && nums[ii] < n && ii != nums[ii] - 1 && nums[ii] != nums[nums[ii] - 1]){
                swap(nums[ii],nums[nums[ii] - 1]);
            }
            else {
                ii++;
            }
        }

        for(int i = 0;i<n;i++){
            cout<<nums[i]<<endl;
            if(nums[i] != i + 1) return i+1;
        }
        return n+1;
    }
};