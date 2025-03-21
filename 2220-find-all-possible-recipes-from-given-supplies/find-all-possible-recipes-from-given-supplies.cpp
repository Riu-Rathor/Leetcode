class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, vector<int>> adj;
        unordered_set<string> st(supplies.begin(), supplies.end());
        vector<int> indegree(n, 0);
        queue<int> q;
        vector<string> result;


        for(int i=0; i<n; i++) {
            for(string &ingredient : ingredients[i]) {
                if(!st.count(ingredient)) {
                    adj[ingredient].push_back(i);
                    indegree[i]++;
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int i = q.front();
            q.pop();
            string recipe = recipes[i];
            result.push_back(recipe);

            for(int &idx : adj[recipe]) {
                indegree[idx]--;
                if(indegree[idx] == 0) {
                    q.push(idx);
                }
            }
        }
        return result;
    }
};