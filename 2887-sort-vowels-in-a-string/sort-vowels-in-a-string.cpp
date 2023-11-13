class Solution {
public:

    bool isVowel(char ch) {
         if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
            return false;
    }
    string sortVowels(string s) {        
        unordered_map<char, int> mp;
        string vowel = "AEIOUaeiou";
        int n = s.length();
        for(int i=0; i<n; i++) {
            if(isVowel(s[i])) {
                mp[s[i]]++;
            }
                      
        }

        int j = 0;
        for(int i=0; i<n; i++) {
            if(isVowel(s[i])) {
                while(true) {
                    if( mp[vowel[j]] > 0) {
                        s[i] = vowel[j];
                        mp[vowel[j]]--;
                        break;
                    }
                    j++;
                }
                
            }
        }
        return s;
    }
};