class Solution {
public:
    int numberOfMatches(int n) {
        // int ans = 0;
        // while(n) {
        //     if(n&1 == 1) {
        //         ans += (n-1) / 2;  
        //         n = ((n-1) / 2) + 1;        
        //     }
        //     else {
        //         ans += (n/2);
        //         n = n / 2;
        //     }
            
        // }           
        return n - 1;
    }
};