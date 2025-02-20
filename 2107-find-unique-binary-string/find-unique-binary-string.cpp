class Solution {
    void solve(int n, unordered_set<string> &st, string &result, string &output) {
        if (output.length() == n) {
            if (st.find(output) == st.end()) {
                result = output;
            }
            return;
        }


        output.push_back('0');
        solve(n, st, result, output);
        output.pop_back();


        output.push_back('1');
        solve(n, st, result, output);
        output.pop_back();
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st(nums.begin(), nums.end());
        string result = "";
        string output = "";
        solve(n, st, result, output);
        return result;
    }
};