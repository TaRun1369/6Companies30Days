class Solution {
public:
    set<string> dict;
    void recur(string s,int prev,int curr,vector<string> &ans,string ansstr){
        if(curr == s.size() ) {
            if(prev == s.size()){
            ansstr.pop_back();    
            ans.push_back(ansstr);
            }
            return;
        }
        
        // if(curr.size() == s.size() - 1){
        //     string temp = s.substr(prev,curr - prev + 1);
        //     if(dict.find(temp) != dict.end()) {
        //         ansstr += (temp);
        //         ans.push_back(ansstr);
        //     }
        //     return;
        // }

        string temp = s.substr(prev,curr - prev + 1);
            if(dict.find(temp) != dict.end()) {
                // ansstr += (temp);
                temp += " ";
                recur(s,curr+1,curr+1,ans,ansstr + temp);
                temp.pop_back();
            }
            // else{
                recur(s,prev,curr + 1,ans,ansstr);
            // }

        

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        for(auto it:  wordDict) dict.insert(it);
        // strint t = ""; 
        recur(s,0,0,ans,"");
        return ans;
    }
};