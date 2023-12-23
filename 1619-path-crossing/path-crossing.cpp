class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> st;
        int n = path.length();
        int x = 0;
        int y = 0;
        st.insert({0, 0});
        for(int i=0; i<n; i++) {
            if(path[i] == 'N') {
                y++;
            }
            else if(path[i] == 'S') {
                y--;
            }
            else if(path[i] == 'E') {
                x++;
            }
            else if(path[i] == 'W') {
                x--;
            }

            if(st.find({x, y}) != st.end()) {
                return true;
            }
            else {
                st.insert({x, y});
            }
        }
        return false;
    }
};