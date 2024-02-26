class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans;
        int count = 0;
        for(auto it : arr){
            // cout<<" curr " <<it<<endl;
            if(it != 0){
            ans.push_back(it);
            count++;
            }
            else {
                ans.push_back(it);
                ans.push_back(it);
                // cout<<ans.size()<<endl;
                count += 2;
            }

            if(count >= arr.size()){
                if(count > arr.size()) ans.pop_back();
                // cout<<"tutne pe "<<it<<endl;

                arr = ans;
                return;
            }

        }

        // arr = ans;
    }
};