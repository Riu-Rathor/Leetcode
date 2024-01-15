class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        map<int, int> winners;
        map<int, int> loosers;
        for(int i=0; i<n; i++) {
            int winner = matches[i][0];
            int looser = matches[i][1];
            loosers[looser]++;
            if(winners.find(looser) != winners.end()) {
                winners.erase(looser);
            }
            if(loosers.find(winner) == loosers.end()) {
                winners[winner]++;
            }else if(loosers.find(winner) != loosers.end()) {
                if(winners.find(winner) != winners.end()) {
                    winners.erase(winner);
                }
            }
        }
        vector<vector<int>> ans(2);
        for(auto it : winners) {
            ans[0].push_back(it.first);
        }

        for(auto it  : loosers) {
            if(it.second == 1) {
                ans[1].push_back(it.first);
            }
        }
        return ans;
    }
};