

class Solution {
public:


    bool check(vector<int> &arr) {
        int n = arr.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_set<int> st;
        for(int &num : arr) {
            mini = min(mini, num);
            maxi = max(maxi, num);
            st.insert(num);
        }

        if((maxi - mini) % (n - 1) != 0) {
            return false;
        }

        int d = (maxi - mini) / (n - 1);
        int currEle = mini;
        while(currEle < maxi) {
            if(st.find(currEle) == st.end()) {
                return false;
            }
            currEle += d;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans;
        for(int i=0; i<m; i++) {
            int start = l[i];
            int end = r[i];
            vector<int> arr;
            for(int j=start; j<=end; j++) {
                arr.push_back(nums[j]);
            }
            bool isAP = check(arr);
            ans.push_back(isAP);
        }
        return ans;
        
    }
};