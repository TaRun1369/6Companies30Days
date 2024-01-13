class Solution {
public:
    string getHint(string s, string g) {
        vector<int> hash(10,0),hashS (10,0),hashG(10,0);
        int bull = 0,cow = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == g[i]){
                bull++;
            }
            else{
                hash[s[i] - '0']++;
                hash[g[i] - '0']++;
                
            hashS[s[i] - '0']++;
            hashG[g[i] - '0']++;
                // cow++;

            }

        }
        int ans = 0;
        for(int i = 0;i<10;i++){
            cout<<i<<" ";
            cout<<"hash - "<<hash[i]/2<<endl;
            cout<<"hashS - "<<hashS[i]<<endl;
            cout<<"hashG - "<<hashG[i]<<endl;

                ans += min(hashG[i],min(hashS[i],(hash[i] /2)));
        
        }

        string ans1 = to_string(bull) + "A" + to_string(ans) + "B";
        return ans1;
    }
};