class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> hash(26,0);
        for(auto it : s){
            hash[it - 'a']++;
        }
        string ans = "";
        int maxi = *max_element(hash.begin(),hash.end());
        cout<<"maxi - "<<maxi<<endl;
        maxi--;
        for(int i = 0;i<26;i++){
            hash[i] = max(0,hash[i] - maxi);
            cout<<i<<" - "<<hash[i]<<" ";
            
        }
        cout<<endl;

        reverse(s.begin(),s.end());
        for(auto it : s){
            if(hash[it - 'a'] != 0) ans += it;
            hash[it - 'a'] = 0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};