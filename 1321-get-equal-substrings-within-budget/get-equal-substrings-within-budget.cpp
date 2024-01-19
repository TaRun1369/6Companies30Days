class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> cost;
        for(int i = 0;i<s.size();i++){
            cost.push_back(abs(s[i] - t[i]));

        }
        int ans = 0;
        int j = 0;
        for(int i = j;i<cost.size();i++){
            int t = 0;
         j = i;
            int co = 0;
            while(j < cost.size() && t + cost[j] <= maxCost){
                co++;
                t += cost[j];
                j++;
                
            }
            ans = max(ans,co);
        }
        return ans;
    }
};