class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        int n = queries.size();
        vector<int> XORresult;
        int xor_ = 0;
        for(int i=0; i<arr.size(); i++) {
            xor_ = xor_ ^ arr[i];
            XORresult.push_back(xor_);
        }

        for(auto & query : queries) {
            int left = query[0];
            int right = query[1];

            result.push_back(XORresult[right] ^ ((left > 0) ? XORresult[left - 1] : 0));
        }
        return result;
    }
};