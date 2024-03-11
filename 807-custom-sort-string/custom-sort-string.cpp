class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        vector<int> freq(26, 0);
        for(int i=0; i<s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        for(int i=0; i<order.length(); i++) {
            while(freq[order[i] - 'a']--) {
                ans.push_back(order[i]);
            }
        }

        for(int i=0; i<26; i++) {
            while((freq[i]--) > 0) {
                ans.push_back(i + 'a');
            }
        }
        return ans;
    }
};