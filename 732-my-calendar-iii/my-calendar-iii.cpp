class MyCalendarThree {
public:
    map<int,int> mp;
    int maxcount = 0;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int count = 0;
        for(auto it : mp){
            count += it.second;
            maxcount = max(count,maxcount);
        }
        return maxcount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */