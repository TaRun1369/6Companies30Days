// class Solution {
// public:
//     int calculate(string s) {
//         stack<char> operation;
//         stack<int> nos;
//         int ans = 0;
//         for(auto it : s){
//             if(it == ' ') continue;
//             else if(it == '(' || it == '+' || it == '-'){
//                 operation.push(it);
//             }
//             else if(it == ')'){
//                 while(!nos.empty() && !operation.empty() && operation.top() != '('){
//                     char op = operation.top();
//                     operation.pop();

//                     int no1 = nos.top();
//                     nos.pop();
//                     int no2 = nos.top();
//                     nos.pop();
//                     if(op == '+'){
//                         ans += no1+ no2;
//                     }
//                     else ans += (no2 - no1);
//                 }
//             }
//             else{
//                 nos.push(it - '0');
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int num = 0;
        int sign = 1; // 1 represents positive, -1 represents negative
        int result = 0;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // Handle multi-digit numbers
            } else if (c == '+' || c == '-') {
                result += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                // Push the result and the sign onto the stack
                nums.push(result);
                ops.push(sign);
                // Reset the result and sign for the new sub-expression
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                // Result is the result of the expression inside the parenthesis
                result *= ops.top(); // This is the sign before the parenthesis
                ops.pop();
                result += nums.top(); // This is the result calculated before the parenthesis
                nums.pop();
            }
        }
        result += sign * num; // Add the last number
        return result;
    }
};
