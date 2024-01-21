class Solution {
public:
    bool checkOverlap(int r, int h, int k, int x1, int y1, int x2, int y2) {
        int dx,dy;
        if(h < x1){
            dx = x1;

        }
        else if(h > x2){
            dx = x2;

        }
        else {
            dx = h;
        }

         if(k < y1){
             cout<<"idhar"<<endl;
            dy = y1;

        }
        else if(k > y2){
            cout<<"idhar1"<<endl;
            dy = y2;

        }
        else {
            cout<<"idhar2"<<endl;
            dy = k;
        }
        cout<<dx<<endl;
        cout<<dy<<endl;
        cout<<(h-dx)<<endl;
        cout<<(k-dy)<<endl;
        return (h-dx) * (h-dx) + (k-dy)*(k-dy) <= (r*r);
    }
};