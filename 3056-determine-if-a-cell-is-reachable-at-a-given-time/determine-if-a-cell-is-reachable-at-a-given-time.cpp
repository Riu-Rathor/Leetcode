class Solution {

public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
       int horizontal = abs(fy-sy);
       int vertical = abs(fx-sx);
       if(horizontal == 0 && vertical == 0 && t == 1) {
           return false;
       } 
       int time = max(horizontal, vertical);
       if(t < time) {
           return false;;
       }
       
       return true;
    }
};