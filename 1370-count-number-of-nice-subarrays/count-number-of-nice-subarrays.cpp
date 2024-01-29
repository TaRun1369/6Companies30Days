class Solution {
public:
   int numberOfSubarrays(vector<int>& nums, int k) {
    int ans=0, sum=0;
    unordered_map<int,int> freq;
    for(auto a:nums){
        if(a%2!=0) ++sum;
        if(sum==k) ++ans;
        if(freq.count(sum-k)) ans += freq[sum-k];
        ++freq[sum];
    }
    return ans;
}
};