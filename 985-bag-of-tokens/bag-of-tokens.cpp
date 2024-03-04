class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i = 0,j = n-1;
        sort(tokens.begin(),tokens.end());
        int maxi = 0,currans = 0;
        while(i<=j){
            if(power >= tokens[i]){
                power -= tokens[i];
                currans++;
                maxi = max(maxi,currans);
                i++;
            }
            else if(currans >= 1){
                power += tokens[j];
                currans--;
                j--;
            }
            else{
                return maxi;
            }
        }
        return maxi;
    }
};