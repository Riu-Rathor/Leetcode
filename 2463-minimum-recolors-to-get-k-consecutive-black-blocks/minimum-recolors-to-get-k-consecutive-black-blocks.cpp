class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int i = 0;
        int j = 0;
        int w = 0;
        int result = k;

        while(j < n) {

            if(blocks[j] == 'W') {
                w++;
            }

            if(j-i+1 == k) {
                result = min(result, w);
                if(blocks[i] == 'W') {
                    w--;
                }
                i++;
            }            
            j++;
        }
        return result;
    }
};