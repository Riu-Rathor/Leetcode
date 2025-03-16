class Solution {
    bool isPossible(vector<int> &ranks, int cars, long long time) {
        long long n = 0;
        for(int i=0; i<ranks.size(); i++) {
            n += sqrt(time / ranks[i]);
        }
        return n >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int max = *max_element(ranks.begin(), ranks.end());

        long long l = 1;
        long long r = 1LL * max * cars * cars;
        long long result = -1;

        while(l <= r) {
            long long mid = l + (r-l)/2;

            if(isPossible(ranks, cars, mid)) {
                result = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return result;
    }
};