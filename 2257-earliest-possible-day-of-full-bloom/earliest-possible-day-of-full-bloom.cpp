class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();

        vector<pair<int, int>> vec(n);

        for(int i=0; i<n; i++) {
            vec.push_back({plantTime[i], growTime[i]});
        }

        auto comparator = [&](pair<int, int> P1, pair<int, int> P2) {
            return P1.second > P2.second;
        };

        sort(vec.begin(), vec.end(), comparator);
        int maxBloomDays = 0;
        int prevPlantDays = 0;

        for(int i=0; i<n; i++) {
            int currPlantTime = vec[i].first;
            int currGrowTime = vec[i].second;

            prevPlantDays += currPlantTime;
            int bloomTime = prevPlantDays + currGrowTime;

            maxBloomDays = max(maxBloomDays, bloomTime);
        }
        return maxBloomDays;
    }
};