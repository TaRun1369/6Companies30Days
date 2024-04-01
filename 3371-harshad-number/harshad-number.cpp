class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int summ = 0;
        int t = x;

        while(t != 0){
            summ += t%10;
            t/=10;
        }
        if(x%summ == 0) return summ;
        return -1;
    }
};