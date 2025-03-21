class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st(supplies.begin(), supplies.end());

        vector<string> result;
        int lastSize = -1;

        queue<int> q;
        for(int i=0; i<recipes.size(); i++) {
            q.push(i);
        }
 
        while(static_cast<int>(st.size()) > lastSize) {
            lastSize = st.size();
            int size = q.size();

            while(size--) {
                int idx = q.front();
                bool canCreate = true;
                q.pop();

                 for(string &ingredient : ingredients[idx]) {
                    if(!st.count(ingredient)) {
                        canCreate = false;
                        break;
                    }
                }

                if(!canCreate) {
                    q.push(idx);
                }
                else {
                    st.insert(recipes[idx]);
                    result.push_back(recipes[idx]);
                }
            }           
        }
        return result;
    }
};