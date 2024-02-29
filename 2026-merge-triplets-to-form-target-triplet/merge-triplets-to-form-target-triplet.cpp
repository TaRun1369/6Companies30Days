class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& trip, vector<int>& t) {
       
        vector<int> final(3,INT_MIN);
        for(auto it : trip){
                bool fl = false;
                if(it[0] <= t[0] && it[1] <= t[1] && it[2] <= t[2]){ fl = true;
                final[0] = max(it[0],final[0]);
                final[1] = max(it[1],final[1]);
                final[2] = max(it[2],final[2]);
                }
        }
        
        // for(auto it : ind){
            
        // }
        if(final == t) return true;
        return false;
    }
};