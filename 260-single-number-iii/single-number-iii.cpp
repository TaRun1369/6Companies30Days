class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xort = 0;
        for(auto it : nums) xort ^= it;
        cout<<xort<<endl;
        long long rightmostbitsetnumber = (xort & (xort - 1)) ^ xort;
        cout<<rightmostbitsetnumber<<endl;
        long long b1 = 0,b2 = 0;

        for(auto it : nums){
            if(it & rightmostbitsetnumber){
                cout<<it<<endl;
                b1 ^= it;
            }
            else b2^=it;
        }
        return {int(b1),int(b2)};
    }
};