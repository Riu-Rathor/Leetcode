class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;
        int n = garbage.size();
        int G_indx = 0;
        int P_indx = 0;
        int M_indx = 0;

        vector<int> prefixSum(travel.size());
        prefixSum[0] = travel[0];
        for(int i=1; i<travel.size(); i++) {
            prefixSum[i] = travel[i] + prefixSum[i-1];
        }

         
        for(int i=0; i<n; i++) {
            string temp = garbage[i];
            time += temp.size();
            for(int j=0; j<temp.length(); j++) {
                if(temp[j] == 'M') {
                    M_indx = i;
                }
                else if(temp[j] == 'P') {
                    P_indx = i;
                }
                else if(temp[j] == 'G'){
                    G_indx = i;
                }
            }
        }

         if (M_indx > 0) {
        time += prefixSum[M_indx-1];
        }
        if (P_indx > 0) {
            time += prefixSum[P_indx-1];
        }
        if (G_indx > 0) {
            time += prefixSum[G_indx-1];
        }
        return time;
    }
};