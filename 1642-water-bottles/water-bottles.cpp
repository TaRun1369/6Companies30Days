class Solution {
public:
    int numWaterBottles(int num, int numex) {
        int currempty = num,ans = num,currfull = 0;
        while(currempty >= numex){
            currfull = currempty/numex;
            // cout<<currfull<<endl;
            ans += currfull;
            int m = currempty %numex;
            currempty = currfull + m;
        }
        return ans;
    }
};