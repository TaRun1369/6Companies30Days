class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry = 0;
        digits[0]++;
        for(auto &it : digits){
            cout<<"it before - "<<it<<endl;
            it += carry;
            cout<<it<<" - it     carry - "<<carry<<endl;
            if(it > 9){
                carry = 1;
                it = 0;
            }
            else carry = 0;
            if(carry == 0) break;
        }
        if(carry == 1) digits.push_back(carry);

        reverse(digits.begin(),digits.end());
        return digits;
    }
};