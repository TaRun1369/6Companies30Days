class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }

        stack<char> st1;
        for(int i = 0;i<t.size();i++){
            if(t[i] == '#'){
                if(!st1.empty()){
                    st1.pop();
                }
            }
            else{
                st1.push(t[i]);
            }
        }

        if(st == st1) return true;
        return false;
    }
};