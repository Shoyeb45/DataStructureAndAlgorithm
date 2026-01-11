class Solution {
public:
    int find_ans(vector<int> &a) {
        int n = a.size();
        vector<int> nge(n, n), pge(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] < a[st.top()]) {
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[i] < a[st.top()]) {
                pge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int ng = nge[i];
            int pg = pge[i];
            ans = max(ans, a[i] * (ng - pg - 1));
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        // 3 1 3 2 2
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> a(m);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') a[j] = 0;
                else a[j]++;
            }
            ans = max(ans, find_ans(a));
        }    
        return ans;
    }
};  