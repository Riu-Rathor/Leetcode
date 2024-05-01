class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int firstOccurence = 0;
        for(int i=0; i<n; i++) {
            if(word[i] == ch) {
                firstOccurence = i;
                break;
            }
        }

        // reverse the substring
        int i = 0;
        while(i < firstOccurence) {
            swap(word[i], word[firstOccurence]);
            i++;
            firstOccurence--;
        }
        return word;
    }
};