class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        int ans = 0;
        for(char &ch : allowed) {
            st.insert(ch);
        }

        for(string &word : words) {
            bool isConsistent = true;
            for(char &ch : word) {
                if(st.find(ch) == st.end()) {
                    isConsistent = false;
                    break;
                }
            }

            if(isConsistent) {
                ans++;
            }
        }
        return ans;
    }
};