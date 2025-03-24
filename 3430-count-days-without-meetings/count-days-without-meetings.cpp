class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int start = 0;
        int end = 0;
        int result = 0;

        for(vector<int> &meeting : meetings) {
            if(meeting[0] > end) {
                result += meeting[0] - end - 1;
            }

            end = max(end, meeting[1]);
        }

        if(days > end) {
            result += days - end;
        }
        return result;
    }
};