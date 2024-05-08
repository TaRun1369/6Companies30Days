class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);

        vector<pair<int,int>> s;

        for(int i = 0;i<n;i++){
            s.push_back({score[i],i});
        }
        sort(s.rbegin(),s.rend());
        int cnt = 1;
        for(auto it : s){
            
            if(cnt == 1){
                ans[it.second] = "Gold Medal";
            }
            else if(cnt == 2){
                ans[it.second] = "Silver Medal";
            }
            else if(cnt == 3){
                ans[it.second] = "Bronze Medal";
            }
            else{
                ans[it.second] = to_string(cnt);
            }
            cnt++;
        }
        return ans;
    }
};