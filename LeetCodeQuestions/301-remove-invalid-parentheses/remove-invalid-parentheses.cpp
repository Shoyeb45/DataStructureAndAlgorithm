#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL); 

class Solution {
    unordered_set<string> ans;
public:
    int findMinOperation(string &s) {
        int openCount = 0;
        int removeCount = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                openCount++;
            } else if (ch == ')') {
                if (openCount > 0) {
                    openCount--;
                } else {
                    removeCount++;
                }
            }
        }
        
        return removeCount + openCount;
    }
    
    void f(string &s, int index, int openCount, int removeLeft, string &current) {
        // Base case: reached the end of the string
        if (index == s.size()) {
            if (openCount == 0 && removeLeft == 0) {
                ans.insert(current);
            }
            return;
        }
        
        // Current character
        char c = s[index];
        
        // Skip non-parentheses characters
        if (c != '(' && c != ')') {
            current.push_back(c);
            f(s, index + 1, openCount, removeLeft, current);
            current.pop_back();
            return;
        }
        
        // Option 1: Remove the current parenthesis if we have removals left
        if (removeLeft > 0) {
            f(s, index + 1, openCount, removeLeft - 1, current);
        }
        
        // Option 2: Keep the current parenthesis
        if (c == '(') {
            current.push_back(c);
            f(s, index + 1, openCount + 1, removeLeft, current);
            current.pop_back();
        } else if (c == ')' && openCount > 0) {
            current.push_back(c);
            f(s, index + 1, openCount - 1, removeLeft, current);
            current.pop_back();
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        NFS
        // Calculate minimum operations required
        int minRemove = findMinOperation(s);
        
        // Use set for unique results
        ans.clear();
        
        // Initialize an empty string for building results
        string current;
        
        // Start backtracking
        f(s, 0, 0, minRemove, current);
        
        // Handle empty result case
        if (ans.empty()) {
            return {""};
        }
        
        return vector<string>(ans.begin(), ans.end());
    }
};