class Solution {
public:

    bool static comparator(int a, int b) {
        string temp1 = to_string(a);
        string temp2 = to_string(b);
        return temp1 + temp2 > temp2 + temp1;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        string ans = "";
        sort(nums.begin(), nums.end(), comparator);
        if(nums[0] == 0) {
            return "0";
        }

        for(int i=0; i<n; i++) {
            ans += to_string(nums[i]);
        }
        return ans;
    }
};