class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> result(n, 0);
        vector<vector<int>> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = {nums1[i], i, nums2[i]};
        }

        sort(arr.begin(), arr.end());
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<n; i++) {
            int num1 = arr[i][0];
            int idx = arr[i][1];
            int num2 = arr[i][2];

            if(i > 0 && arr[i-1][0] == arr[i][0]) {
                long long ans = result[arr[i-1][1]];
                result[idx] = ans;
            }
            else {
                result[idx] = sum;
            }            
            
            pq.push(num2);
            sum += num2;
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return result;
    }
};