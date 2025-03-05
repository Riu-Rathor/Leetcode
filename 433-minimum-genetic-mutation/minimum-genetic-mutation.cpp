class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());
        unordered_set<string> visited;
        int level = 0;

        queue<string> q;
        q.push(startGene);

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string curr = q.front();
                q.pop();
                if(curr == endGene) {
                    return level;
                }

                for(char ch : "ACGT") {
                    for(int i=0; i<8; i++) {
                        string ngbr = curr;
                        ngbr[i] = ch;
                        if(visited.find(ngbr) == visited.end() && bankset.find(ngbr) != bankset.end()) {
                            visited.insert(ngbr);
                            q.push(ngbr);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};