class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x == y) return (x*4 + z*2);
        else return (min(x,y)*4 + 2 + z*2);
    }
};