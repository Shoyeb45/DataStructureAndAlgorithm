class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> a;
    
    RandomizedSet() {
        
    }

    bool search(int val) {
        if (mp.find(val) != mp.end()) return true;
        return false;
    }
    
    bool insert(int val) {
        cout << "insert \n";
        if (search(val)) return false;
        a.push_back(val);
        mp[val] = a.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!search(val)) return false;
        int idx = mp[val];

        a[idx] = a.back();
        a.pop_back();

        mp[a[idx]] = idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        cout << a.size() << "\n";
        return a[rand() % a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */