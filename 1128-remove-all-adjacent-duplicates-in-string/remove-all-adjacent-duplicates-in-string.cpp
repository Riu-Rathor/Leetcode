class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        for(int i=0; i<s.length(); i++) {
            if(result.length() > 0 && result.back() == s[i]) {
                result.pop_back();
            }
            else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};