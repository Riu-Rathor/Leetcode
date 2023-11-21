class Solution {
    int rev(int num) {
        int ans = 0;
        while(num) {
            int digit = num % 10;
            num = num / 10;
            ans = (ans * 10) + digit;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int result = 0;
        for(int i=0; i<n; i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }

        for(int i=0; i<n; i++) {
            result = (result + mp[nums[i]]) % 1000000007;
            mp[nums[i]]++;
        }
        return result;

    }
};