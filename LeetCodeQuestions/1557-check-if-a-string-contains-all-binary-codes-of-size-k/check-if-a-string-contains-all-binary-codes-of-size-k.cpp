class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;

        for (int i = 0; i < s.size(); i++) {
            string t = s.substr(i, k);
            if (st.find(t) == st.end() && t.size() == k) {
                st.insert(t);
            }
        }
        int len = (1 << k);


        for (auto x: st) 
            cout << x << " ";
        return st.size() == len;
    }
};

