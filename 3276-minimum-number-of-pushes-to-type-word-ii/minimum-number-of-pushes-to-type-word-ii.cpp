class Solution {
public:
    int minimumPushes(string word) {
        int result = 0;
        int count = 0;
        int add = 1;
        vector<int> mp(26, 0);
        for(char &ch : word) {
            mp[ch-'a']++;
        }
        auto lambda = [](int &num1, int &num2) {
            return num1 > num2;
        };
        
        sort(mp.begin(), mp.end(), lambda);
        for(int i=0; i<26; i++) {
            int freq = mp[i];
            result += freq * add;
            count++;
            if(count == 8) {
                count = 0;
                add++;
            }
        }
        return result;
    }
};