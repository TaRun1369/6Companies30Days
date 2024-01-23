class Solution {
public:
    int countCollisions(string directions) {
        stack<char> s;
        int res = 0;
        for(char dir : directions) {
            if(s.empty()) s.push(dir);
            else {
                if(dir=='L'){
                    if(s.top()=='R'){
                        res+=2;
                        s.pop();
                        s.push('S');
                    }else if(s.top()=='S') res++;
                    else s.push(dir);
                }else if(dir=='R') s.push(dir);
                else {
                    if(s.top()=='R'){
                        res++;
                        s.pop();
                    }
                    s.push(dir);
                }
            }
        }
        int cnt = 0;
        while(!s.empty()){
            char dir = s.top();
            s.pop();
            if(dir=='R') res+=cnt;
            else if(dir=='S') cnt = 1;
        }
        return res;
    }
};