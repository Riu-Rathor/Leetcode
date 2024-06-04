class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int result = 0;
        for(char &ch : s) {
            if(st.count(ch)) {
                result += 2;
                st.erase(ch);
            }
            else {
                st.insert(ch);
            }
        }

        if(!st.empty()) {
            return result + 1;
        }
        return result;
    }
};