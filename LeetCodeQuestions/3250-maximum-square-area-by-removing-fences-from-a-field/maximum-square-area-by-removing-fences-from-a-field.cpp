class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        set<int> st;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                st.insert(hFences[j] - hFences[i]);
            }
        }


        int ans = -1;

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int diff = vFences[j] - vFences[i];
                if (st.count(diff)) ans = max(ans, diff);
            }
        }

        if (ans == -1) return ans;

        const int mod = (int) 1e9 + 7;
        long long answer = (long long) ans * ans % mod;
        return (int)answer;
    }
};