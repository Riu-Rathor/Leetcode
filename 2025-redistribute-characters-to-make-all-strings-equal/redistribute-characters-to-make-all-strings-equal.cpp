class Solution {
public:
    bool makeEqual(vector<string>& words) {

        int n = words.size();
        // if(n == 1) {
        //     return true;
        // }
        int freq[26] = {0};
        for(string &word : words) {
            for(char &ch : word) {
                freq[ch-'a']++;
            }
        }

        for(auto &it : freq) {
            if(it % n != 0) {
                return false;
            }
        }
        return true;
    }
};