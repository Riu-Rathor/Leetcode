class Solution {

    int solve(string &word, unordered_map<char, int> mp) {
        int n = word.length();
        for(char &ch : word) {
            if(mp[ch] <= 0) {
                return 0;
            }
            else {
                mp[ch]--;
            }
        }
        return n;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(char &ch : chars) {
            mp[ch]++;
        }


        int result = 0;
        for(string &word : words) {
            result += solve(word, mp);
        }
        return result;
    }
};