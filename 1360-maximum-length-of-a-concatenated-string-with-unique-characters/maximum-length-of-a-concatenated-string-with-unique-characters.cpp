class Solution {
    bool isValid(int index, vector<string> &arr, unordered_map<char, int> &mp) {        
        bool isPresent = false;
        unordered_map<char, int> temp;
        for(int i=0; i<arr[index].length(); i++) {
            if(mp.find(arr[index][i]) != mp.end()) {
                isPresent = true;
                break;
            }
            if(temp.find(arr[index][i]) != temp.end()) {
                isPresent = true;
                break;
            }
            temp[arr[index][i]]++;            
        }
        return isPresent;
    }

    int solve(int index, int n, vector<string> &arr, unordered_map<char, int> &mp) {
        if(index >= n) {
            return 0;
        }
        int include = 0;
        int exclude = 0;        

        if(!isValid(index, arr, mp)) {
            for(int i=0; i<arr[index].length(); i++) {
                mp[arr[index][i]]++;
            }
            include = arr[index].length() + solve(index+1, n, arr, mp);
            for(int i=0; i<arr[index].length(); i++) {
                mp.erase(arr[index][i]);
            }
        }
        exclude = solve(index+1, n, arr, mp);
        return max(include, exclude);
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        unordered_map<char, int> mp;
        return solve(0, n, arr, mp);
    }
};