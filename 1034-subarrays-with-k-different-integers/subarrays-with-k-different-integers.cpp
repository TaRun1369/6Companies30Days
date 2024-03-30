class Solution {
public:
    int func(vector<int> &nums,int k){
         map<int,int> mp;
        int j = 0,ans = 0,n = nums.size(),prev = 0;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            
            if(mp.size() > k){
                while(j < n && mp.size() > k){
                    mp[nums[j]]--;
                    if(mp[nums[j]] == 0){
                        mp.erase(nums[j]);
                    }
                    j++;
                }                
            }

            if(mp.size() <= k) ans+= (i - j + 1);
            cout<<"ans - "<<ans<<endl;
            
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    return func(nums,k) - func(nums,k-1);
    }
};