class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int mh = 1,mv = 1;
        sort(hBars.begin(),hBars.end());
         sort(vBars.begin(),vBars.end());
        int c = 1;
        for(int i = 1;i< hBars.size();i++){
            if(hBars[i] == hBars[i-1] + 1){
                c++;
            }
            else{
                c=1;
            }
            mh = max(mh ,c);
        }
        c = 1;
        for(int i = 1;i< vBars.size();i++){
            if(vBars[i] == vBars[i-1] + 1){
                c++;
            }
            else {
                c = 1;
            }
            mv = max(mv ,c);
        }
        int x = min(mv,mh) + 1;
        return x*x;

    }
};