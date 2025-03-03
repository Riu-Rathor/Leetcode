class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int smallerThanPivot = 0;
        int pivotCount = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] < pivot) {
                smallerThanPivot++;
            }

            if(nums[i] == pivot) {
                pivotCount++;
            }
        }

        vector<int> result(n);
        int j = 0;
        int k = smallerThanPivot;

        while(pivotCount--) {
            result[k] = pivot;
            k++;
        }

        for(int i=0; i<n; i++) {
            if(nums[i] < pivot) {
                result[j] = nums[i];
                j++;
            }
            else if(nums[i] > pivot) {
                result[k] = nums[i];
                k++;
            }
        }
        return result;
    }
};