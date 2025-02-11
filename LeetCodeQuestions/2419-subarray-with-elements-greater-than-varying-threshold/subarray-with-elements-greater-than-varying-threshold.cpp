class Solution {
public:
    vector<int> gen_next_smallest_element(vector<int> &a) {
        vector<int> ans(a.size(), (int)a.size());
        stack<int> st;

        for (int i = 0; i < a.size(); i++) {
            while (!st.empty() && a[i] < a[st.top()]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> gen_prev_smallest_element(vector<int> &a) {
        vector<int> ans(a.size(), -1);
        stack<int> st;

        for (int i = a.size() - 1; i >= 0; i--) {
            while (!st.empty() && a[i] < a[st.top()]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    void print(vector<int> &a) {
        for (auto x : a) {
            cout << x << " ";
        }
        cout << "\n";
    }

    int validSubarraySize(vector<int>& a, int t) {
        // fix the a_i as a minimum and get the longest subarray
        // Get the next and prev smallest

        vector<int> nse = gen_next_smallest_element(a);
        vector<int> pse = gen_prev_smallest_element(a);
        // print(nse);
        // print(pse);
        int ans = -1;

        for (int i = 0; i < a.size(); i++) {
            int len = (nse[i] - 1) - (pse[i] + 1) + 1;
            cout << len << " " << i << "\n";
            if (a[i] > t / len) {
                ans = len;
                break;
            }
        }
        return ans;
    }
};