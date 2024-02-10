class Solution {
public:
    
    bool palin(string &x,int l=0,int h=0){
        h=x.size()-1;
        while(l<h){
            if(x[l]!=x[h]) return false;
            l++;
            h--;
        }
        return true;
    }
    
    void help(string &s,int &ans,int ind,string &x){
        if(palin(x) && x.size()>0) ans++;
        if(ind == s.size()) return;
        for(int i=ind+1;i<s.size();i++){
            x+=s[i];
            // cout<<x<<"\n";
            help(s,ans,i,x);
            x.pop_back();
            if(x.size()>0) break;
        }
        
    }
    
    int countSubstrings(string s) {
        int ans=0;
        string x="";
        help(s,ans,-1,x);
        return ans;
    }
};