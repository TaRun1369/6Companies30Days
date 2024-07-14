// class Solution {
// public:
//     bool isno(char ff){
//         if(ff >= '0' && ff <= '9') return true;
//         else return false;
//     }
//     string countOfAtoms(string formula) {
//         stack<string> st;
//         map<string,int> mp;
//         string ch = "";
//         // string ans = "";
//         int n = formula.size();
//         for(int i = 0;i<n;i++){
//             char it = formula[i];
//             if(it >= 'A' && it <= 'Z'){
//                 if(ch == ""){
//                     ch += it;
//                 }
//                 else{
//                     st.push(ch);
//                     mp[ch] = 1;
//                     ch = "";
//                     ch += it;
//                 }
//             }
//             else if(it >= 'a' && it <= 'z'){
//                 ch += it;
//             //    st.push(ch);
//             //    mp[ch] = 1;
//             //    ch = "";
//             }
//             else if(it == '('){
//                 string temp = "";

//                 temp += it;
//                 st.push(temp);
//             }
//             else if(it == ')'){
//                 // int tem = stoi(formula[i + 1]);
//                 string no = "";
//                 i++;
//                 while(i < n && isno(formula[i])){
//                     no += formula[i];
//                     i++;
//                 }
//                 string temp = "";
//                 while(!st.empty() && st.top() != "("){
//                     temp += st.top();
//                     st.pop();
//                 }
//                 int numm = stoi(no);
//                 reverse(temp.begin(),temp.end());
//                 string buff = "";
//                 for(int j =0;j<temp.size();j++){
//                     if(temp[j] >= 'A' && temp[j] <= 'Z'){
//                         if(buff != "") {
//                             mp[buff] += numm;
//                         }
//                         buff += temp[j];
//                     }                   
//                     else if(temp[j] >= 'a' && temp[j] <= 'z'){
//                         buff += temp[j];
//                     } 
//                     else{
//                         string num = "";
//                         num += temp[j];
//                         j++;
//                         while(j < temp.size() && isno(temp[j])){
//                             num += temp[j];
//                             j++;
//                         }
//                         // int n
//                         mp[buff] += stoi(num)*numm;
//                         buff = "";
//                     }

//                 }
//             }
//             else{
//                 string no = "";
//                 while(i < n && isno(formula[i])){
//                     no += formula[i];
//                     i++;
//                 }
//                 i--;
//                 int num = stoi(no);
//                 mp[ch] = num;
//                 ch = "";
//             }
//         }
//         string ans = "";
//         for(auto it : mp){
//             ans += it.first;
//             ans += to_string(it.second);
//         }
//         return ans;
        

//     }
// };
class Solution {
public:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        map<string, int> current;
        
        int n = formula.size();
        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                st.push(current);
                current.clear();
                i++;
            } else if (formula[i] == ')') {
                int i_start = ++i;
                while (i < n && isDigit(formula[i])) i++;
                int multiplier = (i_start < i) ? stoi(formula.substr(i_start, i - i_start)) : 1;
                
                if (!st.empty()) {
                    map<string, int> top = st.top();
                    st.pop();
                    for (auto &p : current) {
                        top[p.first] += p.second * multiplier;
                    }
                    current = top;
                }
            } else {
                int i_start = i;
                i++;
                while (i < n && formula[i] >= 'a' && formula[i] <= 'z') i++;
                string atom = formula.substr(i_start, i - i_start);
                i_start = i;
                while (i < n && isDigit(formula[i])) i++;
                int count = (i_start < i) ? stoi(formula.substr(i_start, i - i_start)) : 1;
                
                current[atom] += count;
            }
        }
        
        string result;
        for (auto &p : current) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        return result;
    }
};
