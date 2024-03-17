class Solution {
public:
    bool check(string t,set<string> wordDict){
       if(wordDict.find(t) == wordDict.end()) return false;
       return true;

    }
    
    void recur(string &s,int ind,set<string> ss,string &ans,vector<string> &ass){
        if(ind == s.size()){
            
            ass.push_back(ans);
        }
        string temp;
        for(int j = ind;j<s.size();j++){
            cout<<temp<<endl;
            if(check(temp,ss) == true ){
                ans+= temp;

                ans += " ";
                // for(int)
                // cout<<ans<<endl;
                recur(s,j,ss,ans,ass);
                for(int i = 0;i<temp.size() + 1;i++){
                    ans.pop_back();
                }
                

            }
            temp += s[j];
        }

        if(check(temp,ss) == true ){
                ans+= temp;

                // ans += " ";
                // for(int)
                // cout<<ans<<endl;
                recur(s,s.size(),ss,ans,ass);
                for(int i = 0;i<temp.size();i++){
                    ans.pop_back();
                }
                

            }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string ans = "";
        vector<string> ass;
        set<string> ss(wordDict.begin(),wordDict.end());
        // for(auto it : wordDict){
        //     s
        // }
        recur(s,0,ss,ans,ass);
        return ass;
    }
};