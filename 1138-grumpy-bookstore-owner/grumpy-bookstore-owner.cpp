class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        // 0 0 0 2 2 3 3 8
        int n = c.size();
        vector<int> pref (n,0);
        int pre = 0;
        for(int i = 0;i<n;i++){
            pre += g[i] * c[i];
            pref[i] = pre;
        }
        
        // for(auto it : pref) cout<<it<<" ";

        int maxi = pref[m-1];
        int i = m,end = m-1;
        while(i < n){
            if(pref[i] - pref[i - m] > maxi){
                maxi = pref[i] - pref[i-m];
                end = i;
            }
            i++;
        }

        cout<<maxi<<" - "<<end<<endl;

        // for(int j = end;j>end - m;j--){
        //     g[j] = 1;
        // }

        // for(auto it : g) cout<<it<<" ";
        int ans = maxi;
        for(int i = 0;i<n;i++){
            if(g[i] == 0){
                ans += c[i];
            }
        }
        
        return ans;

    }
};