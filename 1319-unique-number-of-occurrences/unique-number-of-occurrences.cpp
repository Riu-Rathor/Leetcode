class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int num : arr) {
            mp[num]++;
        }

        unordered_set<int> st;
        for(auto it : mp) {
            if(st.find(it.second) != st.end()) {
                return false;
            }
            st.insert(it.second);
        }
        return true;
    }
};