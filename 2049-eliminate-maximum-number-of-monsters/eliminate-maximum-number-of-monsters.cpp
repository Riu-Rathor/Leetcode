class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int timePassed = 1;
        int count = 1;
        int n = dist.size();
        vector<int> time(n);
        for(int i=0; i<n; i++) {
            time[i] = ceil((float)dist[i] / speed[i]);
        }

        sort(time.begin(), time.end());
        for(int i=1; i<n; i++) {
            if(time[i] - timePassed <= 0) {
                return count;
            }

            count++;
            timePassed++;
        }
        return count;
    }
};