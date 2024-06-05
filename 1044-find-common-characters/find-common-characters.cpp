class Solution {

    void fillCount(string word, vector<int> &count) {
        for(char &ch : word) {
            count[ch - 'a']++;
        }
    }
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        int n  = words.size();
        vector<int> count(26, 0);

        fillCount(words[0], count);

        for(int i=1; i<n; i++) {
            vector<int> temp(26, 0);

            fillCount(words[i], temp);

            for(int i=0; i<26; i++) {
                count[i] = min(count[i], temp[i]);
            }
        }

        for(int i=0; i<26; i++) {
            int c = count[i];
            while(c--) {
                result.push_back(string(1, i+'a'));
            }
        }
        return result;
    }
};