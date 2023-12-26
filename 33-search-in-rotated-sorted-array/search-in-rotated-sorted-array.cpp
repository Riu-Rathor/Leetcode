class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        while(s <= e) {
            int mid = s + (e-s) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            // checking which half is sorted whether it is left half or right half
            if(nums[s] <= nums[mid]) {  // left half is sorted
                if(target >= nums[s] && target <= nums[mid]) {
                    e = mid - 1;
                }
                else {
                    s = mid + 1;
                }
            }
            // if right half is sorted
            else {
                if(target >= nums[mid] && target <= nums[e]) {
                    s = mid + 1;
                }
                else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};