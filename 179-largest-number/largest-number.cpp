class Solution {
    bool static comparator (int num1, int num2) {
            string temp1 = to_string(num1);
            string temp2 = to_string(num2);
            return temp1 + temp2 > temp2 + temp1;
        }
public:
    string largestNumber(vector<int>& nums) {
        string result = "";
        
        sort(nums.begin(), nums.end(), comparator);
        if(nums[0] == 0) {
            return "0";
        }

        for(int i=0; i<nums.size(); i++) {
            result += to_string(nums[i]);
        }
        return result;
    }
};