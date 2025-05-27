class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = (n * (n+1))/2;
        int divisibleSum = 0;
        for(int i=1; i<=n; i++) {
            if(i % m == 0) {
                divisibleSum += i;
            }
        }

        int nonDivisibleSum = totalSum - divisibleSum;
        return nonDivisibleSum - divisibleSum;
    }
};