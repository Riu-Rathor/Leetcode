class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i<=n; i++) {
            q.push(i);
        }

        while(q.size() > 1) {
            for(int count=1; count<=k-1; count++) {
                int front = q.front();
                q.pop();
                q.push(front);
            }

            q.pop();
        }
        return q.front();
    }
};