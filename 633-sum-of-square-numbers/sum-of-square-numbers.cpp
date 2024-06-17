class Solution {
public:
    bool isperfectsquare(int a){
        int l = pow(a,0.5);
        if(pow(l,2) == a) return true;
        return false;
    }
    bool judgeSquareSum(int c) {
        // a^2 + b^2 = c
        // (a+b)^2 = c + 2ab
        // (a-b)^2 = c - 2ab
        // 2c = (a+b)^2 + (a-b)^2;
        // a = a+b/sqrt(2) && b = a-b/sqrt(2)
        // 85 - 36 + 49 
        if(isperfectsquare(c) == true) return true;
        long long l = 0,h = sqrt(c);
        while(l <= h){
            long long l2 = l*l*1ll;
            long long h2 = h*h*1ll;
            if(l2 + h2 == c) return true;
            else if(l2 + h2 > c) h--;
            else l++;
        }
        return false;
    }
};