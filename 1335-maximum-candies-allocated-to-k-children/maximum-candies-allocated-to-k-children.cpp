class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxC = 0;
        long long totalCandy = 0;
        int minC = 1;
        for(int i=0; i<n; i++) {
            maxC = max(maxC, candies[i]);
            minC = min(minC, candies[i]);
            totalCandy += candies[i];
        }

        if(totalCandy < k) {
            return 0;
        }
        int result = 0;

        while(minC <= maxC) {
            int mid = minC + (maxC - minC) / 2;
            long long count = 0;
            for(int i=0; i<n; i++) {
                if(mid != 0) {
                    count += candies[i] / mid;
                }
            }

            if(count >= k) {
                result = mid;
                minC = mid + 1;             
            } 
            else {
                maxC = mid - 1;
            }
        }
        return result;
    }
};