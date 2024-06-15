class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        unordered_set<int> mp;
       int ans=INT_MAX;
       for(auto ele : nums)
       {
            unordered_set<int> nmp;
            nmp.insert(ele);
            for(auto val : mp)
                nmp.insert( (val|ele) );
            swap(nmp,mp);
            for(auto ele : mp)
                ans=std::min(ans,abs(ele-k));
       }
       return ans;
    }
};