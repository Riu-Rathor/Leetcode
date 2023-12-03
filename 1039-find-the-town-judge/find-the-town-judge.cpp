class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans = -1; 
        int size = trust.size();
        vector<pair<int, int>> arr(n+1, {0, 0});

        for(int i=0; i<size; i++) {
            arr[trust[i][0]].first++; 
            arr[trust[i][1]].second++; 
        }


        for(int i=1; i<=n; i++) {
            if(arr[i].first == 0 && arr[i].second == n-1) {
                return i;
            }
        }
        return ans;
    }
};