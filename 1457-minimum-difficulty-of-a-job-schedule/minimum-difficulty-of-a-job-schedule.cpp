class Solution {
public:
    // int finalresult = INT_MAX;
    int memo[305][1005];
    int recur(int d,vector<int> &jd,int ind){
        if(d == 1){
            int maxD = jd[ind];
            for(int i = ind;i<jd.size();i++){
                maxD = max(maxD,jd[i]);
            }
            return maxD;
        }
        if(memo[d][ind] != -1) return memo[d][ind];

        int finalresult = INT_MAX,maxd = jd[ind];
        for(int i = ind;i<= jd.size()- d;i++){
            maxd = max(maxd,jd[i]);

            int result = maxd + recur(d-1,jd,i + 1);
            finalresult = min(finalresult, result);
           
        }
         

         return memo[d][ind] = finalresult;
    }
    int minDifficulty(vector<int>& jd, int d) {
        
        if(jd.size() < d) return -1;

        memset(memo,-1,sizeof(memo));
        return recur( d,jd,0);

    }
};