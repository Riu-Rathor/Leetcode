class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefXOR(arr.begin(), arr.end());
        prefXOR.insert(prefXOR.begin(), 0);
        int n = prefXOR.size();

        for(int i=1; i<n; i++) {
            prefXOR[i] ^= prefXOR[i-1];
        }

        int triplets = 0;
        for(int i=0; i<n; i++) {
            for(int k=i+1; k<n; k++) {
                if(prefXOR[k] == prefXOR[i]) {
                    triplets += k - i - 1;
                }
            }
        }
        return triplets;
    }
};