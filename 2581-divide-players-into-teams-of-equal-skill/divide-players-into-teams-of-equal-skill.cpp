class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        
        sort(skill.begin(), skill.end());
        int i = 0;
        int j = skill.size() - 1;
        int pairSum = skill[i] + skill[j];
        while(i < j) {
            if((skill[i] + skill[j]) != pairSum) {
                return -1;
            }
            ans += (skill[i] * skill[j]);
            i++;
            j--;
        }
        return ans;
    }
};