class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int ropen = 0;
        int rclose = 0,n = s.size();
        int open = 0,close = 0;
        string ans = "";
        stack<int> so,sc;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                // open++;
                so.push(i);
            }
            else if(s[i] == ')'){
                // close++;
                if(so.empty()){
                    rclose++;
                    sc.push(i);
                }
                else{
                    so.pop();
                }
            }
        }

        // ropen = st.size();

        for(int i = n-1;i>=0;i--){
            if(s[i] == '('){
                if(!so.empty() && so.top() == i){
                    so.pop();
                    // continue;
                }else{
                    ans += s[i];
                }
            }
            else if(s[i] == ')'){
                if(!sc.empty() && sc.top() == i){
                    sc.pop();
                    // continue;
                }
                else{
                    ans+= s[i];
                }
            }
            else{
                ans += s[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};