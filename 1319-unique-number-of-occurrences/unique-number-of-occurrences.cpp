class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2002, 0);
        for(int num : arr) {
            freq[num+1000]++;
        }
        sort(freq.begin(), freq.end());
        for(int i=1; i<2002; i++) {
            if(freq[i] != 0 && freq[i] == freq[i-1]) {
                return false;
            }
        }
        return true;
    }
};