class Solution {
public:
    bool checkOverlap(int r, int xC, int yC, int x1, int y1, int x2, int y2) {
        // for x1 wala line
        for(int y = y1;y <= y2;y++){
            int val = (x1-xC)*(x1-xC) + (y-yC)*(y-yC);
            if(val <= r*r) return true; 
        }
         // for x1 wala line
        for(int y = y1;y <= y2;y++){
            int val = (x2-xC)*(x2-xC) + (y-yC)*(y-yC);
            if(val <= r*r) return true; 
        }
         // for y1 wala line
        for(int x = x1;x <= x2;x++){
            int val = (x-xC)*(x-xC) + (y1-yC)*(y1-yC);
            if(val <= r*r) return true; 
        }
         // for y2 wala line
        for(int x = x1;x <= x2;x++){
            int val = (x-xC)*(x-xC) + (y2-yC)*(y2-yC);
            if(val <= r*r) return true; 
        } 

        if(xC < max(x1,x2) && yC < max(y1,y2) && xC > min(x1,x2)&& yC > min(y1,y2)) return true;

        return false;       
        


    }
};