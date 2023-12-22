class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        int i = 0;
        int j = 0;
        while(j < n) {
            // calculation part
            while(!dq.empty() && dq.back() < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(nums[j]);

            if(j-i+1 < k) {
                j++;
            }
            else if(j-i+1 == k) {
                // finding the answer
                ans.push_back(dq.front());
                if(dq.front() == nums[i]) {
                    dq.pop_front();
                }

                // slide the window
                i++;
                j++;
            }
        }
        return ans;
    }
};