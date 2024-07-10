class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(auto it : logs){
            if(it == "../"){
                if(!st.empty()) st.pop();
            }
            else if(it == "./"){
                // kuch nhi
            }
            else{
                string t = "";
                int i = 0;
                while(it[i] != '/'){
                    t += it[i];
                    i++;
                }
                st.push(t);
            }
        }
        return st.size();
    }
};