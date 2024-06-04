class Solution {
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'O' || ch == 'I' || ch == 'E' || ch == 'U') {
            return true;
        }
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int first_vowel = 0;
        int second_vowel = 0;
        int n = s.length();
        int i = 0;
        int j = n/2;

        while(j < n) {
            if(isVowel(s[i])) {
                first_vowel++;
            }

            if(isVowel(s[j])) {
                second_vowel++;
            }
            i++;
            j++;
        }
        return first_vowel == second_vowel;
    }
};