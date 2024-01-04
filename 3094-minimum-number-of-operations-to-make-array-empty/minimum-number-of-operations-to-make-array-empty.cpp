class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }

        for(auto it : mp) {
            int num = it.second;
            if(num == 1) {
                return -1;
            }
            ans += num / 3;
            num = num % 3;
            if(num == 1) {
                ans++;
            }
            else {
                ans += num / 2;
            }
        }
        return ans;
    }
};