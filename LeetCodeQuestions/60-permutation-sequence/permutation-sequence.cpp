class Solution {
public:
    int fact[10];
    void genFactorial() {
        fact[1] = 1;
        fact[0] = 1;
        for (int i = 2; i <= 9; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }

    string findKthPerm(vector<int> &a, int k) {
        if (a.empty()) {
            return "";
        }

        if (k == 0) {
            string rev = "";
            for (int i = a.size() - 1; i >= 0; i--) {
                rev += to_string(a[i]);
            }
            return rev;
        }

        int n = a.size();
        int idx = (k + fact[n - 1] - 1) / fact[n - 1];
        string digit = to_string(a[idx - 1]); 
        a.erase(a.begin() + idx - 1);
        // cout << digit << " ";
        return digit + findKthPerm(a, k % fact[n - 1]);
    } 

    string getPermutation(int n, int k) {
        
        genFactorial();
        vector<int> a;

        for (int i = 1; i <= n; i++) {
            a.push_back(i);
        }
        
        return findKthPerm(a, k);
    }
};