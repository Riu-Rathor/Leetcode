class Solution {
public:
    int tribonacci(int n) {
        int one = 0;
        int two = 1;
        int three = 1; 
        if(n == 0) {
            return one;
        }

        if(n == 1 || n == 2) {
            return two;
        }
        long long  ans = 0;
        for(int i=0; i<= n - 3; i++) {
            ans = one + two + three;
            one = two;
            two = three;
            three = ans;
        }
        return ans;
    }
};