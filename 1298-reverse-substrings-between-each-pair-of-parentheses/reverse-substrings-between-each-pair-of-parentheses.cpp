class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        string result = "";
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                st.push(result.size());
            }
            else if(s[i] == ')') {
                reverse(result.begin()+st.top(), result.end());
                st.pop();
            }
            else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};