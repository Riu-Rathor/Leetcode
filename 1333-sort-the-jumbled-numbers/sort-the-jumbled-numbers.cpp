class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> newNums;
        for(int i=0; i<nums.size(); i++) {
            string temp = to_string(nums[i]);
            string newTemp = "";
            for(int j=0; j<temp.size(); j++) {
                int index = (temp[i]);
                newTemp = newTemp + to_string(mapping[temp[j] - '0']);
            }

            newNums.push_back({stoi(newTemp), nums[i]});
        }
        auto lambda = [] (pair<int, int> &p1, pair<int, int> &p2) {
            return p1.first < p2.first;
        };
        sort(newNums.begin(), newNums.end(), lambda);
        vector<int> result;
        for(auto &it : newNums) {
            result.push_back(it.second);
        }
        return result;
    }
};