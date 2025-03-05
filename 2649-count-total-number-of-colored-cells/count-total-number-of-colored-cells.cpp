class Solution {
    long long solve(int n) {
        long long ans = 1;

        for(int i=2; i<=n; i++) {
            ans += 4*(i-1);
        }
        return ans;
    }
public:
    long long coloredCells(int n) {
        return solve(n);
    }
};