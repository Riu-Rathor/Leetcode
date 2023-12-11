class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        int n = strs.size();
        vector<vector<string>> ans;
        for(string str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }

        for(auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};