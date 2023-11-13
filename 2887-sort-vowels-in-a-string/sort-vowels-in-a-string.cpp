class Solution {
public:
    string sortVowels(string s) {
        string vowel = "AEIOUaeiou";
        int n = s.length();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++) {
            mp[s[i]]++;            
        }

        int j = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ||
            s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
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