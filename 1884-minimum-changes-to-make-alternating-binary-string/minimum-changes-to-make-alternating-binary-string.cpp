class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int count1 = 0;
        int count2 = 0;
        for(int i=0; i<n; i++) {
            if(i%2 == 0 && s[i] == '0') {
                count1++;       
            }
            else if(i%2 != 0 && s[i] == '1') {
                count1++;
            }
        }
        return min(count1, n-count1);
    }
};