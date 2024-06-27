class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for(auto edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        int n = mp.size();

        for(auto it : mp) {
            if(it.second.size() == n-1) {
                return it.first;
            }
        }
        return -1;
    }
};