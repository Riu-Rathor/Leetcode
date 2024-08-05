class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        int n = arr.size();
        string result = "";
        for(string &str : arr) {
            mp[str]++;
        }

        for(int i=0; i<n; i++) {
            if(k == 0) {
                return result;
            }
            if(mp[arr[i]] == 1) {
                result = arr[i];
                k--;
            }
        }
        return k ==0 ? result : "";
    }
};