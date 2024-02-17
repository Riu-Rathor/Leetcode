class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<pair<string, int>> temp;
        int n1 = list1.size();
        int n2 = list2.size();
        int minIndex = INT_MAX;
        for(int i=0; i<n1; i++) {
            for(int j=0; j<n2; j++) {
                if(list1[i] == list2[j]) {
                    minIndex = min(minIndex, i+j);
                    temp.push_back({list1[i], i+j});
                }
            }
        }
        vector<string> ans;
        for(int i=0; i<temp.size(); i++) {
            if(temp[i].second == minIndex) {
                ans.push_back(temp[i].first);
            }
        }
        return ans;
    }
};