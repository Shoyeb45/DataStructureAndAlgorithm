class Solution {
public:
    int minOperations(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        vector<int> nse(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] <= a[st.top()]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                int p = i;
                int ele = a[i];
                while (p != -1 && a[p] == ele) {
                    a[p] = 0;
                    p = nse[p];
                }
                ans++;
            }
        }
        return ans;
    }
};