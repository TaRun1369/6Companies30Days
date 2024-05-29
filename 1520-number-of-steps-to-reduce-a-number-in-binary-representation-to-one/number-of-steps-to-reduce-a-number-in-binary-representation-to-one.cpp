class Solution {
public:
    int numSteps(string s) {
        int carry = 0;
        reverse(s.begin(),s.end());
        int ans = 0;
        int n = s.size();
        for(int i = 0;i<n - 1;i++){
            if(s[i] == '1' ){
               if(carry == 1){
                ans += 1;
               }
               else{
                ans += 2;
                carry = 1;
               }

            }
            else{
                if(carry == 1){
                    ans += 2;
                }
                else{
                    ans += 1;
                }
            }
        }
        if(carry== 1)ans++;
        return ans;
    }
};