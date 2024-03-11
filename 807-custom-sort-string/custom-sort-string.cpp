class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        vector<int> hash(26,0);
        for(auto it : order){
            hash[it - 'a']++;
        }
        string ans = "";
        for(auto it : s){
            mp[it]++;
        }

        for(auto it : order){
            auto iss = mp.find(it);
            if(iss != mp.end()){
                ans.insert(ans.end(),iss->second,iss->first);
            }
        }

        for(auto it : s){
            
            if(hash[it - 'a'] == 0){
                ans += it;
            }
        }
        return ans;
    }
};