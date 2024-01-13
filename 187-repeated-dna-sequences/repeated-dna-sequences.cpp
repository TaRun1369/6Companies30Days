class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10) return {}; 
        vector<string> ans;
        map<string,int> mp;
        for(int i = 0;i<s.size()-9;i++){
            // string sub = s.substr(i+1,s.size() - i - 1 );
            string finding = s.substr( i,10);
            mp[finding]++;
        }

        // vector<string>v( ans.begin(), ans.end());
        for(auto it : mp){
            if(it.second > 1) ans.push_back(it.first);
        }
        return ans;
    }
};