class Solution {
public:
    const set<string> valid_cat = {"electronics", "grocery", "pharmacy", "restaurant"};

    bool valid_code(string& code) {
        if (code == "") return false;

        for (auto c: code) {
            if (!isalnum(c) && c != '_')
                return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> ans;

        int n = code.size();
        for (int i = 0; i < n; i++) {
            bool is_active = isActive[i];
            if (!is_active) continue;
            if (valid_cat.count(businessLine[i]) == 0) continue;
            if (!valid_code(code[i])) continue;
            ans.push_back(make_pair(businessLine[i], code[i]));
        }

        sort(ans.begin(), ans.end());
        vector<string> tmp;
        for (auto& x: ans) 
            tmp.push_back(x.second);

        return tmp;
    }

};