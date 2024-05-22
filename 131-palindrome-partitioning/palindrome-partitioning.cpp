class Solution {

    bool isPalindrome(string str, int s, int e) {
        while(s <= e) {
            if(str[s++] != str[e--]) {
                return false;
            }
        }
        return true;
    }

    void solve(string s, int index, vector<string> &path, vector<vector<string>> &ans) {
        if(index == s.length()) {
            ans.push_back(path);
            return;
        }

        for(int i=index; i<s.length(); i++) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i-index+1));
                solve(s, i+1, path, ans);
                path.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(s, 0, path, ans);
        return ans;
    }
};