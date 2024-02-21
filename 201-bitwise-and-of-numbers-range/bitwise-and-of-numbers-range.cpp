class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int num = right;
        int ans = 0;
        while(right > left) {
            right = (right & (right - 1));
        }
        return right;
    }
};