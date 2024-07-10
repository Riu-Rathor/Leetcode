class Solution {

public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(string log : logs) { 
            if(log[0] >= 'a' && log[0] <= 'z' || log[0] >= '1' && log[0] <= '9' || log[0] >= 'A' && log[0] <= 'Z') {
                count++;
            }
            else if(log[0] == '.' && log[1] == '.') {
                count = (count > 0) ? count - 1 : 0;
            }
        }
        return count;
    }
};