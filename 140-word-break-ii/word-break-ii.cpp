class Solution {

    void solve(int i, string curr, string s, vector<string> &result, unordered_set<string> &st) {

        if(i >= s.length()) {
            result.push_back(curr);
            return;
        }
        for(int j=i; j<s.length(); j++) {
            string tempWord = s.substr(i, j-i+1);
            if(st.count(tempWord)) {
                string tempSentence = curr;
                if(!curr.empty()) {
                    curr += " ";
                }
                curr += tempWord;

                solve(j+1, curr, s, result, st);
                curr = tempSentence;
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string currSentence = "";
        vector<string> result;
        unordered_set<string> st;
        for(string &word : wordDict) {
            st.insert(word);
        }

        solve(0, currSentence, s, result, st);
        return result;
    }
};