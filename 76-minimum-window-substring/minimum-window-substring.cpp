class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int countRequired = t.length();
        if(countRequired > n) {
            return "";
        }
        unordered_map<char, int> mp;
        // store the characters of string t in map 
        for(char &ch : t) {
            mp[ch]++;
        }

        int i = 0;
        int j = 0;
        int windowSize = INT_MAX;
        int start_i = 0;

        while(j < n ) {
            char ch = s[j];
            if(mp[ch] > 0) {
                countRequired--;
            }
            mp[ch]--;
            while(countRequired == 0) {
                // shrink the window
                int currWindowSize = j - i + 1;
                if(windowSize > currWindowSize) {
                    windowSize = currWindowSize;
                    start_i = i;
                }

                mp[s[i]]++;
                if(mp[s[i]] > 0) {
                    countRequired++;
                }
                i++;
            }
            j++;
        }

        return windowSize == INT_MAX ? "" : s.substr(start_i, windowSize);
    }
};