class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        long long s = n*(n+1)/2;
        cout<<"s "<<s<<endl;
        // if(s % 2 != 0) return -1;
        for(int i = 1;i<= n ; i++){
            long long ts = i*(i+1)/2;
            cout<<i<<" "<<ts<<endl;
            if((s+i)%2 != 0)continue;
            if(ts == (s+i)/2){
                return i;
            }
        }
        return -1;
    }
};