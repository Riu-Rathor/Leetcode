class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        int countOdd = 0;
        for(char &ch : s) {
            mp[ch]++;
        }

        for(auto it : mp) {
            int num = it.second;
            while(num > 1) {
                ans = ans + (2 * (num / 2));
                num %= 2;
            }

            if(num == 1) {
                countOdd++;
            }
        }

        if(countOdd >= 1) {
            return ans + 1;
        }
        return ans;
    }
};