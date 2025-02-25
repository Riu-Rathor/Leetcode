class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9+7;
        int n = arr.size();
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        int count = 0;

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }

        int odd = 0;
        int even = 1;

        for(int i=0; i<n; i++) {
            if(prefix[i] % 2 == 0) {
                count = (count + odd) % MOD;
                even++;
            }
            else {
                count = (count + even) % MOD;
                odd++;
            }
        }
        return count;
    }
};