class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int min = 0,max = 0;
        vector<int> temp;
        vector<vector<int>> ans;
        for(int i = 0;i<nums.size();i++){
            // cout<<nums[i]<<endl;
            temp.push_back(nums[i]);
            if(i%3 == 0){ 
                min = nums[i];

            }
            if(i%3 == 2){ max = nums[i];if(max - min > k){
                // cout<<"ganda"<<min<<" "<<max<<endl;
                return {};
            }else{
                ans.push_back(temp);
                vector<int> t;
                temp = t;
                min = 0;max = 0;
            }
            }


        }
        return ans;


    }
};