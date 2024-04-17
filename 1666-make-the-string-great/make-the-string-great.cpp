class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for(char ch : s) {
            if(ans.size() > 0 && (ans.back() + 32 == ch || ans.back() - 32 == ch)) {
                ans.pop_back();
            }
            else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};