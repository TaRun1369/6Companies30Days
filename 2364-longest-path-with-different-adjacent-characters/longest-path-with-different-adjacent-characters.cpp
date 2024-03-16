class Solution {
public:
int result = 0;

    int DFS(unordered_map<int,vector<int>>&mp,int curr,int par,string &s){

        int longest = 0;
        int secondlong = 0;

        for( auto it : mp[curr]){
            if(it == par)continue;

            int childlonglen = DFS(mp,it,curr,s);

            if(s[it] == s[curr]) continue;

            if(secondlong < childlonglen) secondlong = childlonglen;

            if(secondlong > longest) swap(longest,secondlong);
        }

        int noachelog = 1;
        int ekacha = max(longest,secondlong) + 1;// 1 for curr node
        int doachematlabpuraans = 1 + longest + secondlong;

        result = max({result,noachelog,ekacha,doachematlabpuraans});

        return max(noachelog,ekacha);

    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int,vector<int>>mp;

        for(int i= 1;i<n;i++){
            int u = i;
            int v = parent[i];
            
            mp[u].push_back(v);
            mp[v].push_back(u);

           
        }
         DFS(mp,0,-1,s);

        return result;
    }
};