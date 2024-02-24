class Solution {
public:
typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj;
        for(vector<int> &meeting: meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }

        queue<P> q;
        q.push({0, 0});
        q.push({firstPerson, 0});
        vector<int> timeToKnowSecret(n, INT_MAX);
        timeToKnowSecret[0] = 0;
        timeToKnowSecret[firstPerson] = 0;
        while(!q.empty()) {
            int person = q.front().first;
            int time = q.front().second;
            q.pop();
            for(auto &ngbr: adj[person]) {
                int nextPerson = ngbr.first;
                int meetTime = ngbr.second;

                if(meetTime >= time && timeToKnowSecret[nextPerson] > time) {
                    timeToKnowSecret[nextPerson] = meetTime;
                    q.push({nextPerson, meetTime});
                }
            }
        }

        vector<int> result;
        for(int i=0; i<n; i++) {
            if(timeToKnowSecret[i] != INT_MAX) {
                result.push_back(i);
            }
        }
        return result;
    }
};