class Solution {
public:
    unordered_map<string, vector<char>> mp;

    unordered_map<string, bool> cache;

    void generate_all(int idx, string &base, string &row, vector<string> &a) {
        if (idx == base.size() - 1) {
            if (row.size() > 0) a.push_back(row);
            return;
        }

        string tmp = base.substr(idx, 2);

        if (mp.find(tmp) != mp.end()) {
            auto vc = mp[tmp];
            for (int j = 0; j < vc.size(); j++) {
                row += vc[j];
                generate_all(idx + 1, base, row, a);
                row.pop_back();
            }
        }
    }

    bool fn(string &base) {
        int n = base.size();
        if (n == 1) return true;

        if (cache.find(base) != cache.end()) return cache[base];
        // generate all the possible rows
        vector<string> a;
        string tmp = "";
        generate_all(0, base, tmp, a);

        if (a.size() == 0) return false;

        bool ans = false;

        for (auto &b: a) {
            ans |= fn(b);
        }

        return cache[base] = ans;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        for (auto &x: allowed) {
            mp[x.substr(0, 2)].push_back(x[2]);
        }    



        return fn(bottom); 
    }
};