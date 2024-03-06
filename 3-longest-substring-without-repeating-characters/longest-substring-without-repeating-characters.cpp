class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;
        int left = 0;
        int ans = 0;
        for(int right=0; right<n; right++) {
            if(st.count(s[right]) == 0) {
                ans = max(ans, right - left + 1);
            }
            else {
                while(st.count(s[right])) {
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(s[right]);
        }
        return ans;
    }
};