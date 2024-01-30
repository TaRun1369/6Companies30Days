class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int n=d.size();
        int m=s.length();
        string ans="";
        for(int i=0;i<n;++i){
            
            // checking weather d[i] is present within "s" using two pointer approach
            string curr=d[i];
            int a=0,b=0;
            string temp="";
            int cc=0; // character count
            while(a<m && b<curr.length()){
                if(s[a]==curr[b]){
                    ++cc;
                    ++b;
                }
                ++a;
            }
            // current word is completely present in "s"
            if(cc==curr.length()){ 
                // check whether "curr" is longer than "ans"
                // OR
                // if "curr" and "ans" are same length then choose the lexicographically smaller one
                if(ans.length()<curr.length() || (ans.length()==curr.length() && curr<ans)){
                    ans=curr;
                }
            }
        }
        
        return ans;
    }
};