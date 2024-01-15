class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp;

        for(auto it : matches){
            if(mp.find(it[0]) == mp.end())
            mp[it[0]] = 0;
            mp[it[1]]--;
        }
        vector<int> ans1,ans2;
        for(auto it : mp){
            if(it.second == -1) ans2.push_back(it.first);
            if(it.second == 0) ans1.push_back(it.first);
        }
        sort(ans1.begin(),ans1.end());
        sort(ans2.begin(),ans2.end());
        return {ans1,ans2};
    }
};