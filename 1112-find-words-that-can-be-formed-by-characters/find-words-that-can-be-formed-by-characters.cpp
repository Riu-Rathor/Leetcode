class Solution {
public:

    int solve(string word, unordered_map<char, int> mp) {
        int n = word.length();
        bool isPresent = true;
        for(int i=0; i<n; i++) {
            if(mp[word[i]] <= 0) {
                isPresent = false;
                break;
            }
            mp[word[i]]--;
        }
        if(isPresent) {
            return n;
        }
        return 0;
    }
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(auto i : chars) {
            mp[i]++;
        }
        int ans = 0;
        for(string word : words) {
            ans += solve(word, mp);
        }
        return ans;
    }
};