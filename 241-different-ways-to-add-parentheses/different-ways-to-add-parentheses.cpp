class Solution {
    vector<int> solve(string s) {
        vector<int> result;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left_result = solve(s.substr(0, i));
                vector<int> right_result = solve(s.substr(i+1));

                for(int &x : left_result) {
                    for(int &y : right_result) {
                        if(s[i] == '+') {
                            result.push_back(x+y);
                        }
                        else if(s[i] == '-') {
                            result.push_back(x-y);
                        }
                        else if(s[i] == '*') {
                            result.push_back(x*y);
                        }
                    }
                }
            } 
        }
        if (result.empty()) {
            return {stoi(s)};
        }
        return result;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};