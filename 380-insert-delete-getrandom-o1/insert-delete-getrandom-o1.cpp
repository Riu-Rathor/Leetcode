class RandomizedSet {
public:
vector<int> v;
unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) {
            return false;
        }
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) {
            return false;
        }
        int index = mp[val];
        int lastElement = v.back();
        v.back() = val;
        v[index] = lastElement;
        mp[lastElement] = index;
        mp.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        int randomIndex = rand() % n;
        return v[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */