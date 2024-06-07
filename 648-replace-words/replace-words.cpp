class Solution {
public:
    string replaceWords(vector<string>& dict, string ss) {
        set<string> s(dict.begin(),dict.end());
        string ans = "";
        int i =0,n = ss.size();
        string temp = "";
        int f = 0;
        while(i < n){
            // cout<<i<<" - index   ans char - "<< ss[i]<<" temp - "<<temp<<endl;
            if((ss[i] == ' ') || (i == (n - 1))){
                if(i == n-1){ temp += ss[n-1];
                // cout<<temp<<endl;
                }
                if(f == 1 || i == n-1){ ans += temp;
                ans += " ";}
                temp = "";
                f = 0;
                i++;
            }
            else{
                temp+=ss[i];
                if(s.find(temp) != s.end()){
                    ans += temp;
                    ans += " ";
                    temp = "";
                    while(i < n && ss[i] != ' ')i++;
                    f = 0;
                }
                else{ f = 1;i++;}
            }
            
        }
        ans.pop_back();
        return ans;
    }
};