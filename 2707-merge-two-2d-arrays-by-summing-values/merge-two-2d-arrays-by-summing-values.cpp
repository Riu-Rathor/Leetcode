class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        vector<vector<int>> result;
        while(i < n1 && j < n2) {
            int id1 = nums1[i][0];
            int val1 = nums1[i][1];
            int id2 = nums2[j][0];
            int val2 = nums2[j][1];
            
            if(id1 == id2) {
                result.push_back({id1, (val1+val2)});
                i++;
                j++;
            }
            else if(id1 < id2) {
                result.push_back({id1, val1});
                i++;
            }
            else {
                result.push_back({id2, val2});
                j++;
            }
        }

        while(i < n1) {
            int id = nums1[i][0];
            int val = nums1[i][1];
            result.push_back({id, val});
            i++;            
        }

        while(j < n2) {
            int id = nums2[j][0];
            int val = nums2[j][1];
            result.push_back({id, val});
            j++;            
        }
        return result;
    }
};