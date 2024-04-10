class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> paisa;
        for(auto it : bills){
            cout<<"it - "<<it<<endl;
            if(it == 5){
                paisa[5]++;
            }
            else if(it == 10){
                paisa[10]++;
                if(paisa.find(5) != paisa.end()){
                    paisa[5]--;
                    if(paisa[5] == 0) paisa.erase(5);
                }
                else return false;
            }
            else if(it == 20){
                cout<<"20 aaya "<<endl;
                // paisa[20]--;
                if(paisa.find(5) != paisa.end()){
                    cout<<"5 hai"<<endl;
                    if(paisa.find(10) != paisa.end()){
                        cout<<"10 hai "<<endl;
                        cout<<paisa[10]<<endl;
                        cout<<paisa[5]<<endl;
                        paisa[10]--;
                        paisa[5]--;
                        if(paisa[10] == 0) paisa.erase(10);
                        if(paisa[5] == 0) paisa.erase(5);
                    }
                    else{
                        cout<<"yaha"<<endl;
                        cout<<"5 kitne hai - "<<paisa[5]<<endl;
                        if(paisa[5] < 3)return false;
                        else {
                            paisa[5] -= 3;
                            if(paisa[5] == 0) paisa.erase(5);
                        }
                    }
                    
                }
                else{
                    cout<<"yaha"<<endl;
                    return false;
                }

            }
        }

        return true;
    }
};