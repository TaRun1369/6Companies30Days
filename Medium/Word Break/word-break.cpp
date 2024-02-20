//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    set<string> ss;
    // bool exist(int i,int j,set<string> &dict,string s){
    //     cout<<"i "<<i<<"j "<<j<<endl;
    //     string sub = s.substr(i,j-i+1);
    //     cout<<sub<<endl;
    //     if(dict.find(sub) != dict.end()){
    //         return true;
    //     }
    //     return false;
    // }
    bool recur(int ind,string s){
        if(ind == s.size()) return true; 
        
        // string temp = s[ind];
        bool ans = false;
        for(int j = ind;j<s.size();j++){
             string sub = s.substr(ind,j-ind+1);
            if(ss.find(sub) != ss.end()){
                ans = ans || recur(j+1,s);
            }
        }
        
        return ans;
    }
    int wordBreak(int n, string s, vector<string> &dict) {
        //code here
        for(auto it : dict) ss.insert(it);
        return recur(0,s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends