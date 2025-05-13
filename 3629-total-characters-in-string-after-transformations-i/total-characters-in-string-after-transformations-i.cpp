class Solution {
public:
    int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        vector<int> mp(26, 0);
        for(char &ch : s) {
            mp[ch-'a']++;
        }

        for(int i=1; i<=t; i++) {
            vector<int> temp(26, 0);

            for(int j=0; j<26; j++) {
                char ch = j + 'a';
                int freq = mp[j];

                if(ch != 'z') {
                    temp[(ch+1) - 'a'] = (temp[(ch+1) - 'a']+freq) % M;
                }
                else {
                    temp[0] = (temp[0]+freq) % M;
                    temp[1] = (temp[1]+freq) % M;
                }
            }
            mp = move(temp);
        }

        int length = 0;
        for(int i=0; i<26; i++) {
            length = (length + mp[i]) % M;
        }
        return length;
    }
};