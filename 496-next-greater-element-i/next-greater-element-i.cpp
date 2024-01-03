class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        for(int i=0; i<n1; i++) {
            int num =  nums1[i];            
            int nextGreater = -1;
            for(int j=n2-1; j>=0; j--) {
                if(nums2[j] == num) {
                    ans.push_back(nextGreater);
                    break;
                }else if(nums2[j] > num) {
                    nextGreater = nums2[j];
                }
            }
        }
        return ans;
    }
};