class Solution {

    bool isPalindrome(string str) {
        int i = 0;
        int e = str.length()-1;
        while(i <= e) {
            if(str[i] != str[e]) {
                return false;
            }
            i++;
            e--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                int length = j - i + 1;
                string temp = s.substr(i, length);
                if(isPalindrome(temp)) {
                    count++;
                }
            }
        }
        return count;
    }
};