class Solution {

    void addOne(string &s) {
        int i = s.length() - 1;
        while(i >= 0 && s[i] != '0') {
            s[i] = '0';
            i--;
        }
        if(i < 0) {
            s = '1' + s;
        }
        else {
            s[i] = '1';
        }
    }
public:
    int numSteps(string s) {
        int operation = 0;
        while(s.length() > 1) {
            int n = s.length();
            if(s[n-1] == '0') {
                s.pop_back();
            }
            else {
                addOne(s);                
            }
            operation++;
        }
        return operation;
    }   
};