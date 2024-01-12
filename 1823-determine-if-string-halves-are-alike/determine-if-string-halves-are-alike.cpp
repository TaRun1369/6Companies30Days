class Solution {
public:
bool isVowel(char x) 
{ 
    if (x == 'a' || x == 'e' || x == 'i' ||  
                   x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O'
                    || x == 'U') 
        return true; 
    else
        return false; 
} 
  
    int countV(string ss){
        int count = 0;
        for(auto it : ss){
            if(isVowel(it)) count++;
        }

        return count;
    }
    bool halvesAreAlike(string s) {
        cout<<s.size()/2<<endl;
        cout<<s.size()/2 - 1<<endl;
        string s1 = s.substr(0,s.size()/2);
        string s2 = s.substr(s.size()/2,s.size()/2);
        cout<<s1<<s2<<endl;
        int c1 = countV(s1);
        int c2 = countV(s2);

        if(c1 == c2){
            return true;
        }
        return false;
    }
};