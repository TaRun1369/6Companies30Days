class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

       int i = 0,j = n-1;
       while(i < j){
           if(s[i] == s[j]){
               while(i+1 < n && s[i] == s[i+1] ){
                   i++;
               }
               while(j -1 >= 0 && s[j] == s[j-1]){
                   j--;
               }
           }
           else{
               return j-i+1;
           }
           i++;
           j--;
       } 
       if(i == j) return 1;
       return 0;
    }
};