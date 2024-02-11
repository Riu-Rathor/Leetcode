class Solution {
    string generate(string &word) {
        vector<int> freq(26, 0);
        for(char &ch : word) {
            freq[ch-'a']++;
        }
        string temp = "";
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                temp += string(freq[i], i + 'a');
            }
        }
        return temp;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(string str : strs) {
            string temp = generate(str);
            mp[temp].push_back(str);
        }

        for(auto &it : mp)  {
            ans.push_back(it.second);
        }
        return ans;

    }
};