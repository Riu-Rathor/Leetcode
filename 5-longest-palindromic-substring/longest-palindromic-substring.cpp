class Solution {

    bool isPalindrome(string &s, int i, int j) {
        if(i >= j) {
            return true;
        }

        if(s[i] == s[j]) {
            return isPalindrome(s, i+1, j-1);
        }
        else {
            return false;
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLength = INT_MIN;
        int start = 0;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(isPalindrome(s, i, j)) {
                    if(j-i+1 > maxLength) {
                        maxLength = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
}; 