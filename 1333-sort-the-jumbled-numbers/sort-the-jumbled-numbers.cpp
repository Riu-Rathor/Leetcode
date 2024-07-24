class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> newNums;
        for(int i=0; i<nums.size(); i++) {
            int newTemp = 0;
            int temp = nums[i];
            int place = 1;
            if(temp == 0) {
                newNums.push_back({mapping[0], nums[i]});
                continue;
            }

            while(temp != 0) {
                newTemp = place * mapping[temp%10] + newTemp;
                place *= 10;
                temp /= 10;
            }
            newNums.push_back({newTemp, nums[i]});
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