class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();

        for(auto it : num){
            if(st.empty() || st.top() <= it){
                st.push(it);

            } 
            else{
                while(k > 0 && (!st.empty() && st.top() > it)){
                    st.pop();
                    k--;
                }
                // if(k <= 0)
                // if(st.size() < num.size() - k)
                st.push(it);
            }
        }

        while(!st.empty() && k > 0) {st.pop(); k--;}
        string ans = "";
       
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
 reverse(ans.begin(),ans.end());
int i = 0;
 while(i < ans.size() && ans[i] == '0') i++;

 string anss = ans.substr(i,ans.size() - i); 
        if(anss == "") return "0";
        return anss;
    }
};