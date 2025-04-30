class Solution {
    int findLength(int n) {
        string num = to_string(n);
        return num.length();
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