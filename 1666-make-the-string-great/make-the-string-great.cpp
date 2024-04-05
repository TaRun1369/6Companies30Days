class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for(auto it : s){
            if(!st.empty() && st.top() != it && tolower(st.top()) == tolower(it)){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};