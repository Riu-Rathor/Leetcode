class Solution {

public:
    vector<vector<int>> ans;
    void solve(int src, int target, vector<int> &path, vector<vector<int>>& graph) {
        if(src == target) {
            ans.push_back(path);
            return;
        }
        for(auto i : graph[src]) {
            path.push_back(i);
            solve(i, target, path, graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // vector<vector<int>> ans;
        int n = graph.size();
        vector<int> path;
        path.push_back(0);
        solve(0, n-1, path, graph);
        return ans;
    }
};