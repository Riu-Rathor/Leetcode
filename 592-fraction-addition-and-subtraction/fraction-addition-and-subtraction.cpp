class Solution {
public:
    string fractionAddition(string exp) {
        int nume = 0;
        int deno = 1;
        int n = exp.length();

        int i = 0;
        while(i < n) {
            int currNum = 0;
            int currDeno = 0;

            bool isNeg = (exp[i] == '-');
            if(exp[i] == '+' || exp[i] == '-') {
                i++;
            }

            while(i < n && isdigit(exp[i])) {
                int val = exp[i] - '0';
                currNum = (currNum * 10) + val;
                i++;
            }
            i++;
            if(isNeg == true) {
                currNum *= -1;
            }

            while(i < n && isdigit(exp[i])) {
                int val = exp[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            nume = (nume * currDeno) + (currNum * deno);
            deno = deno * currDeno;
        }

        
        int GCD = abs(__gcd(nume, deno));
        nume /= GCD;
        deno /= GCD;
        return to_string(nume) + "/" + to_string(deno);
    }
};