// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
//         stack<char>st;
//         int ans = 0;
//         if(y > x){
//         for(auto it : s){
//             if(it == 'a'){
//                 if(!st.empty() && st.top() == 'b'){
//                     cout<<"ba made "<<endl;
//                     st.pop();
//                     ans += y;
//                 }
//                 else st.push(it);
//             }
//             else {
//                 st.push(it);
//             }
//         }
//          stack<char> temp;string tt;
//             while(!st.empty()){
//                 tt.push_back(st.top());
//                 st.pop();
//             }
//             reverse(tt.begin(),tt.end());
//             for(auto it: tt){
//                 if(it == 'b'){
//                     if(!temp.empty() && temp.top() == 'a'){
//                         cout<<"ab when y is greater  "<<endl;
//                         ans += x;
//                     }
//                     else temp.push(it);
//                 }
//                 else temp.push(it);
//             }
//         }
//         else{
//             for(auto it : s){
//             if(it == 'b'){
//                 if(!st.empty() && st.top() == 'a'){
//                     cout<<"ab made "<<endl;
//                     st.pop();
//                     ans += x;
//                 }
//                 else st.push(it);
//             }
//             else {
//                 st.push(it);
//             }
//         }
//         stack<char> temp;string tt;
//             while(!st.empty()){
//                 tt.push_back(st.top());
//                 st.pop();
//             }
//             reverse(tt.begin(),tt.end());
//             for(auto it: tt){
//                 if(it == 'a'){
//                     if(!temp.empty() && temp.top() == 'b'){
//                         cout<<"ba -when x is greater "<<endl;
//                         ans += y;
//                     }
//                     else temp.push(it);
//                 }
//                 else temp.push(it);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;
        
        // Ensure the higher point value is processed first
        char first = 'a', second = 'b';
        int firstVal = x, secondVal = y;
        if (y > x) {
            swap(first, second);
            swap(firstVal, secondVal);
        }

        // First pass: Remove the higher value pairs
        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                ans += firstVal;
            } else {
                st.push(c);
            }
        }
        
        // Collect remaining characters to process the lower value pairs
        string remaining;
        while (!st.empty()) {
            remaining.push_back(st.top());
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        
        // Second pass: Remove the lower value pairs
        for (char c : remaining) {
            if (!st.empty() && st.top() == second && c == first) {
                st.pop();
                ans += secondVal;
            } else {
                st.push(c);
            }
        }

        return ans;
    }
};
