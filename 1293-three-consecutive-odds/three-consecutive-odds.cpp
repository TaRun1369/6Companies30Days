class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int three = 0;
        for(auto it : arr){
            if(it&1){
                three++;
            }
            else three = 0;

            if(three == 3) return true;
        }

        return false;
    }
};