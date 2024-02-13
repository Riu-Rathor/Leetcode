class Solution {
    bool isPalindrome(string &str) {
        int s = 0;
        int e = str.length()-1;
        while(s <= e) {
            if(str[s] != str[e]) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string word : words) {
            if(isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
};