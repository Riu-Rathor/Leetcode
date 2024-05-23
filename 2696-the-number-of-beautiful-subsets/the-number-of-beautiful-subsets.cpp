class Solution {

    void solve(vector<int> &nums, int index, int &ans, int &k, unordered_map<int, int> &mp) {
        if(index == nums.size()) {
            ans++;
            return;
        }
        
        solve(nums, index+1, ans, k, mp);

        if(!mp[nums[index] - k] && !mp[nums[index] + k]) {
            mp[nums[index]]++;
            solve(nums, index+1, ans, k, mp);
            mp[nums[index]]--;
        }


    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        solve(nums, 0, ans, k, mp);
        return ans-1;
    }
};