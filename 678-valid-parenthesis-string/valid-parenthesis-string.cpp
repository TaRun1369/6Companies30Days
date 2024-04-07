class Solution {
public:
    bool checkValidString(string s) {
        int buff = 0,n = s.size();
        stack<int> st,buf;
        int open = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                st.push(i);
                open++;
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                    // open--;
                }
                else{
                    if(buf.size() > 0){
                        buf.pop();
                    }
                    else{
                        cout<<"yaha se gaya"<<endl;
                        return false;
                    }
                }
            }
            else{
                // * hai
                buf.push(i);
            }
        }
        while(!st.empty()){
            int ti = st.top();
            int bt = -1;
            if(!buf.empty())
            bt = buf.top();
            if(bt > ti){
                st.pop();
                buf.pop();
            } 
            else{
                return false;
            }
        }
        return true;
    }
};

// buff - 13
// stack - 13