class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        int result = 0;
        for(int i=0; i<n; i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                char ope = tokens[i][0];
                switch(ope) {
                    case '+' : result =  num2 + num1; break;
                    case '-' : result =  num2 - num1; break;
                    case '*' : result =  num2 * num1; break;
                    case '/' : result =  num2 / num1; break;
                }
                st.push(result);
            }
            else {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};