class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& s) {
        int one = 0,zero = 0, n = s.size();
        for(auto it : students){
            if(it == 1) one++;
            else zero++;
        }
        int i = 0;
        for(;i<n;i++){
            if(s[i] == 1 && one>0) one--;
            else if(s[i] == 0 && zero>0) zero--;
            else break;
        }
        return n-i;
    }
};