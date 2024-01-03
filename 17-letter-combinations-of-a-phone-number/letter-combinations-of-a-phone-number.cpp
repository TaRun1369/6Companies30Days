class Solution {
public:

    void recur(map<char,vector<char> > &mp,vector<string> &ans, string digits,int index, string ansS){
        if(ansS.size() == digits.size()){
            ans.push_back(ansS);
            return;
        }

        for(int i = index;i<digits.size();i++){
            vector<char> temp = mp[digits[i]];
            for(auto it : temp){
                ansS.push_back(it);
                recur(mp,ans,digits,i+1,ansS);
                ansS.pop_back();
            }
        }
    } 
    vector<string> letterCombinations(string digits) {
        int siz = digits.size();
        if(siz == 0){
            return {};
        }
        // vector<int> visited(26,0);
        map<char,vector<char>> mp ;
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};
        vector<string> ans;
        string an;
        recur(mp,ans,digits,0,an);
        return ans;
    }
};