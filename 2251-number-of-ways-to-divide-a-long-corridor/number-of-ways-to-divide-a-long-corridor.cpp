class Solution {

public:
int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int> seats;

        for(int i=0; i<n; i++) {
            if(corridor[i] == 'S') {
                seats.push_back(i);
            }
        }

        if(seats.size() % 2 != 0 || seats.size() == 0) {
            return 0;
        }

        long long int result = 1;
        int prevIndex = seats[1];

        for(int i=2; i<seats.size(); i+=2) {
            int length = seats[i] - prevIndex;
            result = (result * length) % mod;
            prevIndex = seats[i+1];
        }
        return result;

    }
};