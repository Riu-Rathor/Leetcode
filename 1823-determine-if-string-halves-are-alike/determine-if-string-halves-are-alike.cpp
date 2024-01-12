class Solution {
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
               return true;
        }
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int mid = n / 2;
        int vowelA = 0;
        int vowelB = 0;
        for(int i=0; i<mid; i++) {
            if(isVowel(s[i])) {
                vowelA++;
            }
        }

        for(int i=mid; i<n; i++)  {
            if(isVowel(s[i])) {
                vowelB++;
            }
        }
        return vowelA == vowelB;
    }
};