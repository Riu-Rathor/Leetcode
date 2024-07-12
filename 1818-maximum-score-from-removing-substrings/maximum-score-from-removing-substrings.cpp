class Solution {

    string removeSubstr(string s, string &matchStr) {
        stack<char> st;
        for(char &ch : s) {
            if(ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }

        string temp = "";
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;
        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x > y) ? "ba" : "ab";

        // first pass
        string temp_first = removeSubstr(s, maxStr);
        int L1 = temp_first.length();
        int charRemoved = (n - L1);
        score += max(x, y) * (charRemoved / 2);

        // second pass
        string temp_second = removeSubstr(temp_first, minStr);
        int L2 = temp_second.length();
        charRemoved = (temp_first.length() - L2);
        score += min(x, y) * (charRemoved / 2);

        return score;

    }
};