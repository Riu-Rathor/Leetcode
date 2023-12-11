class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
       int n = arr.size();
       int length = n / 4;
        int count = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] == arr[i+length]) {
                return arr[i];
            }
        }
        return -1;
    }
};