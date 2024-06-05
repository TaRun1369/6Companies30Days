class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> hash(26,0);
        for(auto it : words[0]){
            hash[it - 'a']++;
        }

        for(int i = 1;i<words.size();i++){
            vector<int> th(26,0);
            for(auto it : words[i]){
                th[it - 'a']++;
            }

            for(int i= 0;i<26;i++){
                if(th[i] == 0) hash[i] = INT_MIN;
                else{
                    hash[i] = min(th[i],hash[i]);
                }
            }
            

        }

        vector<string> ans;
            for(int i = 0;i<26;i++){
                while(hash[i] > 0){
                    string t = "";
                    t += (i + 'a');
                    ans.push_back(t);
                    hash[i]--;
                } 
            }
        return ans;

    }
};