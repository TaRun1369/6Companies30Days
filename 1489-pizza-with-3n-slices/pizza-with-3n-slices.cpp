// class Solution {
// public:
//     set<int> s;
//     int n;
//     int recur(vector<int> &v,int ind){
//         if(s.size() == v.size()){
//             return 0;
//         }

//         // take
//         int take = INT_MIN;

//         if(s.find(ind) == s.end()) {
//             s.insert((ind + 1)%n);
//             s.insert(ind);
//             s.insert((ind -1 + n) % n);
//             take = v[ind] + recur(v,(ind+2)%n);
//             take = max(take,v[ind] + recur(v , (ind - 2 + n)%n) );
//             s.erase((ind + 1)%n);
//             s.erase(ind);
//             s.erase((ind -1 + n) % n);
//         }

//         // nottake
//         int nottake = recur(v,ind + 1);
//         return max(take,nottake);
         
//     }
//     int maxSizeSlices(vector<int>& slices) {
//         n = slices.size();
//         return recur(slices,0);
//     }
// };

class Solution {
public:
    
    
    int recur(vector<int>& v, int ind , int end,int n,vector<vector<int>> &dp) {
        if(n == 0 || ind > end) return 0;
        if(dp[ind][n] != -1) return dp[ind][n];
        int take = v[ind] + recur(v,ind + 2,end,n-1,dp);
        int nottake = recur(v,ind + 1,end , n,dp);

        return dp[ind][n] = max(take,nottake);
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(n,vector<int>(n,-1)),dp2(n,vector<int>(n,-1));
        return max(recur(slices, 0,n-2,n/3,dp1),recur(slices,1,n-1,n/3,dp2));
    }
};
