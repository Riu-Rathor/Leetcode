class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        int n = paths.size();
        for(int i=0; i<n; i++) {
            string src = paths[i][0];
            mp[src]++;
        }

        for(int i=0; i<n; i++) {
            string dest = paths[i][1];
            if(mp.find(dest) == mp.end()) {
                return dest;
            }
        }
        return "";
        
    }
};