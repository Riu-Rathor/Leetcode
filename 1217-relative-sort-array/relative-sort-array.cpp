class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // sort(arr1.begin(), arr2.end(), lambda());
        map<int, int> mp;
        for(int &num : arr1) {
            mp[num]++;
        }
        int n = arr1.size();
        int i = 0;


        for(int &num : arr2) {
            while(mp[num]--) {
                arr1[i++] = num;
            }            
        }

        for(auto &it : mp) {
            int freq = it.second;
            while(freq-- > 0) {
                arr1[i++] = it.first;
            }
        }
        return arr1;
    }
};