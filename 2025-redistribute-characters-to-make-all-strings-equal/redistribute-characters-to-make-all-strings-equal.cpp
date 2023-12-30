class Solution {
public:
    bool makeEqual(vector<string>& words) {

        int n = words.size();
        if(n == 1) {
            return true;
        }
        unordered_map<char, int> mp;
        for(string word : words) {
            for(char ch : word) {
                mp[ch]++;
            }
        }

        for(auto it : mp) {
            if(it.second % n != 0) {
                return false;
            }
        }
        return true;
    }
};