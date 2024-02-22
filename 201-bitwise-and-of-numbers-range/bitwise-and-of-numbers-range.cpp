class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int s = 0,e = 0;
        if(left > 0)
        s = log2(left);
        if(right > 0)
        e = log2(right);
        // cout<<" log - "<<log2(left)<<endl;
        // cout<<" log - "<<log2(right)<<endl;
        if(e != s) return 0;
        else {
            long ans = left;
            if(right > left)
            for(long i = left+1;i<=right;i++){
                ans = ans & i;

            }
            return ans;
        }
       return s; 
    }
};