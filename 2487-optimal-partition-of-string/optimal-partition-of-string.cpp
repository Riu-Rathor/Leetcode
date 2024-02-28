class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        int ans = 0;
        unordered_set<char> st;
        for(int i=0; i<n; i++) {
            if(st.find(s[i]) != st.end()) {
                ans++;
                st.clear();
            }
            st.insert(s[i]);
        }
        return ans+1;
    }
};