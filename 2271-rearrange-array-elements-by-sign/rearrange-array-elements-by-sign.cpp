class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        // vector<int> ans(nums.size(),)
        for(auto it : nums){
            if(it > 0){
                pos.push_back(it);
            }
            else{
                neg.push_back(it);
            }
        }

        for(int i = 0;i<nums.size();i++){
            if(i%2 == 0) {
                nums[i] = pos[i/2];
            }
            else{
                // i -      1 3 5 7
                // negi -   0 1 2 3
                nums[i] = neg[(i-1)/2];
            }
        }
        return nums;
    }
};