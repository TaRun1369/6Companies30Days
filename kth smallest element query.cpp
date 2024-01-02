typedef pair<string, int> pi; // element,index 


class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto it : queries){
            int k = it[0];
            int katna = it[1];
            priority_queue<pi, vector<pi>,greater<pi>> pq;
            int i = 0;
            for(auto is : nums){
                // int iiii = stoi(is.substr(is.size() - katna - 1,katna));
                string temp=is;
                string res;
                for(int l=temp.size()-katna;l<temp.size();l++)
                    res+=temp[l];
                // int iiii = stoi(res);
                pq.push(make_pair(res,i++));
            }
            pi to;
            while(!pq.empty() && k--){
                to = pq.top();
                pq.pop();
            }

            ans.push_back(to.second);
        }

        return ans;
    }
};
