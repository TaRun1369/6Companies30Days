class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<32;i++){
            int cnt = 0;
            for(auto it : nums){
                if(it & (1 << i))cnt++;
                // cout<<it<<"     "<<cnt<<endl;
            }
            // cout<<i<<"      "<<cnt<<endl;
            if(cnt % 3 == 1) ans = ans |  (1 << i);

        }
        return ans;
    }
};