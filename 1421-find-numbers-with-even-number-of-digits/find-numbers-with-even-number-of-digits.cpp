class Solution {
    int findLength(int n) {
        int count = 0;
        while(n) {
            n = n / 10;
            count++;
        }
        return count;

    }
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(int &num : nums) {
            if(findLength(num) % 2 == 0) {
                result++;
            }
        }
        return result;
    }
};