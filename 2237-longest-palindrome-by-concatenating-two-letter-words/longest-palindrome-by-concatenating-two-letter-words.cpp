class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> mp;

        for(string &word : words) {
            mp[word]++;
        }

        bool centerUsed = false;
        int result = 0;
        for(string &word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if(rev != word) {
                if(mp[word] > 0 && mp[rev] > 0) {
                    result += 4;
                    mp[word]--;
                    mp[rev]--;
                }
            }
            else {
                if(mp[word] >= 2) {
                    result += 4;
                    mp[word] -= 2;
                }
                else if(mp[word] > 0 && !centerUsed) {
                    result += 2;
                    mp[word]--;
                    centerUsed = true;
                }
            }
        }
        return result;
    }
};