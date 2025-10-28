class Solution {
public:
    bool allZero(vector<int> &a) {
        for (auto x : a) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
    bool validLeft (int idx, vector<int> a) {
        bool isLeft = 1;
        for (int i = idx - 1; i >= 0 && i < a.size(); ) {
            if (a[i] == 0) {
                if (isLeft) {
                    i--;
                }
                else {
                    i++;
                }
                continue;
            }
            
            if (a[i] > 0) {
                a[i]--;
                if (isLeft) {
                    i++;
                    isLeft = 0;
                }
                else {
                    i--;
                    isLeft = 1;
                }
            }
        }
       
        return allZero(a);
    }

    bool validRight (int idx, vector<int> a) {
        bool isRight = 1;
        for (int i = idx + 1; i >= 0 && i < a.size(); ) {
            if (a[i] == 0) {
                if (isRight) {
                    i++;
                }
                else {
                    i--;
                }
                continue;
            }
            
            if (a[i] > 0) {
                a[i]--;
                
                if (isRight) {
                    i--;
                    isRight = 0;
                }
                else {
                    i++;
                    isRight = 1;
                }
            }
        }

        return allZero(a);
    }
    int countValidSelections(vector<int>& a) {
        int ans = 0, n = a.size();

        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                if (validLeft(i, a)) {
                    ans++;
                }
                if (validRight(i, a)) {
                    ans++;
                }
            }
        } 
        return ans;
    }
};