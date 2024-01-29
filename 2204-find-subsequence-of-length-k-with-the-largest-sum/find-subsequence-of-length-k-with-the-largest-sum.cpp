class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       priority_queue<pair<int,int>> pq;
        vector<int> ans;
       for(int i = 0;i<nums.size();i++){
           pq.push({nums[i],i});
       }
map<int,int> mp;
        while(!pq.empty() && k > 0){
            cout<<pq.top().first<<" "<<pq.top().second<<endl;
            mp[pq.top().second] = pq.top().first;
            pq.pop();
            k--;
        }
       for(auto it : mp){
           cout<<it.first<<" "<<it.second<<endl;
           ans.push_back(it.second);
       }
       return ans;
       
    }
};