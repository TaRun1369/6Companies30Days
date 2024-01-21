class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0;
        int j = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] >= g[j]){
                ans++;
                
                if(j<g.size()-1)
                j++;
                else break;
            }
            
        }
        return ans;
    }
};