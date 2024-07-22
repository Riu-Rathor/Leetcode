class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;
        int n = heights.size();
        for(int i=0; i<n; i++) {
            mp[heights[i]] = names[i];
        }
        vector<string> result;
        for(auto &it : mp ) {
            result.push_back(it.second);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};