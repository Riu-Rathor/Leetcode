class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = 0;
        int xorResult = start ^ goal;

        while(xorResult) {
            result += xorResult & 1;
            xorResult >>= 1;
        }
        return result;

    }
};