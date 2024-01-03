class DataStream {
public:
    int k;
    int val;
    int res;
    DataStream(int value, int K) {
        val=value;
        k=K;
        res=0;
    }
    
    bool consec(int num) {
        if(num==val) res++;
        else res=0;

        if(res>=k) return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */