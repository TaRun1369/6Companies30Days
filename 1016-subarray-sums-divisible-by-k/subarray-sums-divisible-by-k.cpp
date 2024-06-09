class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int n = nums.size();
        int ans = 0;
        for(int i =0;i<n;i++){
            sum += nums[i];
            int r = sum%k;
            if(r < 0) r += k;

            if(mp.find(r) != mp.end()){
                cout<<"i - "<<i<<endl;
                ans += mp[r]; 
                cout<<ans<<endl;
            }

            mp[r]++;
        }

        return ans;
    }
};