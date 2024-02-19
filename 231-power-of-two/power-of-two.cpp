class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == -2147483648) return false;
        if(n == 0 )return false;
        if( n == 1) return true;
        int l = log2(abs(n));
        int k = pow(2,l);
        if(k == n) return true;
        else return false;
    }
};