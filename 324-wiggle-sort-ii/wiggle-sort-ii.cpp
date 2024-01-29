class Solution {
public:
    int nextindex(int i, int n){
        i = i + 2;
        if(!(i<n)){
            i = 0;
        }
        return i;
    }
    void wiggleSort(vector<int>& nums) {
        if(nums.size()==1){
            return;
        }
        int sorter[5001] = {0}, n = nums.size();
        for(int i=0;i<n;i++){
            sorter[nums[i]]++;
        }
        int cind = 1;
        for(int i=5000;i>=0;i--){
            while(sorter[i]>0){
                nums[cind] = i;
                sorter[i]--;
                cind = nextindex(cind,n);
            }
        }
        return;
    }
};