class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        if(s[s.size() - 1] == '0'){
            // string ans = "";
            int k = 0;
            for(int i = s.size() - 2;i >= 0;i--){
                if(s[i] == '1'){
                    k = i;
                    break;
                }
               
            }
             swap(s[k],s[s.size() - 1]);

                int coun = 0;
        
            for(int i = 0;i<s.size() - 1;i++){
                if(s[i] == '1')coun++;
            }

            string ans = "";
            for(int i = 0;i<coun;i++){
                ans+='1';
            }
            for(int i=0;i<s.size() - 1 - coun;i++){
                ans += '0';
            }
            ans += '1';


            return ans;
        }
        else{
            int coun = 0;
        
            for(int i = 0;i<s.size() - 1;i++){
                if(s[i] == '1')coun++;
            }

            string ans = "";
            for(int i = 0;i<coun;i++){
                ans+='1';
            }
            for(int i=0;i<s.size() - 1 - coun;i++){
                ans += '0';
            }
            ans += '1';
            return ans;
        }
    }
};