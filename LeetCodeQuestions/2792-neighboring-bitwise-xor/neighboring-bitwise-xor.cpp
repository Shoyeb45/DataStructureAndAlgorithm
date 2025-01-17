class Solution {
public:
    int required(int given, int target) {
        if ((given == 1 && target == 0) || (given == 0 && target == 1)) {
            return 1;
        }
        return 0;
    }
    bool isValid(int first, int last, int n, vector<int> &derived) {
        vector<int> a(n);
        a[0] = first, a[n - 1] = last;
        int predicted = first;
        for (int i = 1; i < n - 1; i++) {
            a[i] = required(a[i - 1], derived[i - 1]);
        }
      
        return required(a[n - 2], derived[n - 2]) == a[n - 1];
    }

    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size(); 
        if (n == 1) {
            return !(derived.front());
        }
        if (derived.back() == 0) {
            if (isValid(1, 1, n, derived) || isValid(0, 0, n, derived)) {
                return true;
            }
            return false;
        }

        return isValid(1, 0, n, derived) || isValid(0, 1, n, derived);
    }
};