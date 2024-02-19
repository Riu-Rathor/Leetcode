class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i = 0;
        while(true) {
            long long num = pow(2, i);
            if(num == n) {
                return true;
            }

            if(num > n) {
                break;
            }
            i++;
        }
        return false;
    }
};