class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        int mini = min(n1, min(n2, n3));
        int ans = -1;
        for(int i=0; i<mini; i++) {
            if(s1[i] == s2[i] && s2[i] == s3[i]) {
                ans = n1 - (i+1) + n2 - (i+1) + n3 - (i+1);
            }
            else {
                break;
            }           
        }

        
        return ans;
    }
};