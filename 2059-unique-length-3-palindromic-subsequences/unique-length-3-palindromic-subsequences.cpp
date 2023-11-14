class Solution {
public:

    bool isPalindrome(string s1, string s2) {
        int s = 0;
        int e = s1.length();
        while(s < e) {
            if(s1[s] != s2[e]) {
                return false;
                s++;
                e--;
            }
        }
        return true;
    }


    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> indices(26, {-1, -1});

        for(int i=0; i<n; i++) {
            char ch = s[i];
            int idx = ch - 'a';
            if(indices[idx].first == -1) {
                indices[idx].first = i;
            }

            indices[idx].second = i;
        }





        int result = 0;
        for(int i=0; i<26; i++) {            
            unordered_set<char> st;
            int firstIndex = indices[i].first;
            int lastIndex = indices[i].second;

            if(firstIndex == -1 || lastIndex == -1) {
                continue;
            }
            for(int middle = firstIndex+1; middle<=lastIndex-1; middle++) {
                st.insert(s[middle]);
            }

            result += st.size();
        }
        return result;
    }
};