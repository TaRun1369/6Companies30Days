class Solution {
public:
    int minNonZeroProduct(int p) {
        long long ans = ((long long)(1)<<p) -1;
        int base = (1000000000+7);
        long long cur = ans  -1; 
        cur  = cur%base;
        ans = ans % base;

        int k = 0;
        while(k<=p-2){
            ans *= cur;
            cur *= cur;

            ans %= base;
            cur %=base;
            k++;
        } 
        return ans;
    }
};