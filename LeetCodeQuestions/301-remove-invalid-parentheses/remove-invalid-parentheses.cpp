#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
    set<string> ans;
public:
    int findMinOperation(string &s) {
        stack<int> st;
        int ans = 0;
        for (char ch : s) {
            if (ch != '(' && ch != ')') {
                continue;
            }

            if (ch == '(') {
                st.push(ch);
            }
            else {
                if (st.empty()) {
                    ans++;
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
            }
        }
        
        return ans + st.size();
    }

    bool valid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c != '(' && c != ')') {
                continue;
            }

            if (c == '(') {
                st.push(c);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
            }
        }
        
        return st.empty();
    }
    int count = 0;
    void f(int idx, string &s, string &temp, int oper, int open, int close) {
        count++;
        if (idx == s.size()) {
            if (open == close && oper == 0) {
                ans.insert(temp);
            }
            return; 
        }

        if (s[idx] != '(' && s[idx] != ')') {
            temp.push_back(s[idx]);
            f(idx + 1, s, temp, oper, open, close);
            temp.pop_back();
            return;
        }

        if (s[idx] == '(') {
            temp.push_back(s[idx]);
            f(idx + 1, s, temp, oper, open + 1, close);
            temp.pop_back();

            if (oper > 0) {
                f(idx + 1, s, temp, oper - 1, open, close);
            }
        } else if (s[idx] == ')') {
            if (close < open) {
                temp.push_back(s[idx]);
                f(idx + 1, s, temp, oper, open, close + 1);
                temp.pop_back();
            }
            if (oper > 0) {
                f(idx + 1, s, temp, oper - 1, open, close);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        NFS
        int mnOperation = findMinOperation(s);
        cout << mnOperation << "\n";
        string d;
        f(0, s, d, mnOperation, 0, 0);
        cout<<count<<"\n";
        if (ans.empty()) {
            return {""};
        }
        return vector<string>(ans.begin(), ans.end());
    }
};